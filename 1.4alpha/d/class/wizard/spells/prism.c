/*
** File: prism.c (Prismatic SPray)
** Purpose: 7th level wizard conjuration spell.
**   When cast upon a target, it may do one of 8 things (12.5% chance
**   for each) :
**        Red - 60 points of magic damage.
**     Orange - 120 points of acid damage.
**     Yellow - 240 points of fire damage.
**      Green - Die or take 60 points of poison damage.
**       Blue - Save or be turned to stone.
**     Indigo - Save of be feebleminded.
**     Violet - Save or be sent to another plane.
** Cost: 80 SP
** Credits:
**    3 Aug 97  Cyanide lovingly created this file.
*/

#include <config.h>
#include <daemons.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 80

string get_color(int);
void do_color(string, object, int);
void do_dmg(object, int, string, int);
void do_green (object, int);
void do_blue (object, int);
void do_indigo (object, int);
void do_violet (object, int);

object caster;
object *places = ({
  "/d/Ancients/rooms/post_office",
  "/d/Ancients/rooms/bugroom",
  "/d/Ancients/rooms/wizrm",
  "/d/Prime/Toril/Arabel/room/slrm/rm1",
  "/d/Outer/Baator/avernus/ave1.c",
});

inherit SPELL;

varargs int cast_prism (string str, int obj) {
  object targ;
  int ran, ran2 = 0;

  if (!str) str = "NONE";
  if (str=="NONE") targ = TP->query_current_attacker();
  else targ = present(str, environment(TP));

  seteuid(getuid());

  if (!targ) {
    write ("Cast Prismatic Spray at what or who?\n");
    return 0;
  }
  if (!check_valid_targ(TP, targ)) return 0;  
 if (!check_magic_resist((TP->query_level("wizard")), targ, COST, 0)) return 0;
  
  if (!obj) {
    tell_object(TP, "You begin casting Prismatic Spray...\n");
    tell_room(environment(TP), TPN+" utters a strange incantation.\n",
      ({ TP }) );

  if (!this_player()->cast_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }      

    tell_room(environment(TP), wrap("Brilliant rays of multicolored"+
      " light stream from "+TPN+"'s hands!"), ({ TP }) );
    tell_object(TP, wrap("Brilliant rays of multicolored"+
      " light stream from your hands!"));
  }
  
  obj = targ->save_throw();   //Reusing a variable - sorry.

  if (obj) {
    if (targ->query_skill("Evasion")) {
      tell_object(targ, "You deftly dodge all of the rays!\n");
      tell_room(environment(targ), targ->query("cap_name")+ 
        " deftly dodges all of the rays!\n", ({ targ }) );
      return 1;
    }
  }

  caster = TP;
  ran = random(8);
  if (ran) {
    str = " hit by the "+get_color(ran)+" ray!";
    
    tell_object(targ, wrap("You get"+str));
    tell_room(environment(targ), wrap(targ->query("cap_name")+" gets"+
      str), ({targ}) );
    do_color(get_color(ran), targ, obj);
  } else {
    while (ran2<=ran) {      // The while loop ensures you don't get
      ran = random(7)+1;     // identical rolls or sent away to another
      ran2 = random(7)+1;    // plane before other bad stuff can happen
    }                        // to you.
  
    str = " hit by both the "+get_color(ran)+" and "+get_color(ran2)+
      " rays!";
    tell_room(environment(targ), wrap(targ->query("cap_name")+" gets"+
      str), ({ targ }) );
    tell_object(targ, wrap("You get"+str));
    do_color(get_color(ran), targ, obj);
    do_color(get_color(ran2), targ, targ->save_throw());
  }    

  targ->kill_ob(TP);
  return 1;
}

string get_color(int ran) {
  string c;

  switch (ran) {
    case 1 : c = "red"; break;
    case 2 : c = "orange"; break;
    case 3 : c = "yellow"; break;
    case 4 : c = "green"; break;
    case 5 : c = "indigo"; break;
    case 6 : c = "violet"; break;
    default : c = "blue"; break;
  }

  return c;
}


void do_color(string color, object targ, int sv) {
  switch (color) {
    case "red" : do_dmg(targ, sv, "magic", 60); break;
    case "orange" : do_dmg(targ, sv, "acid", 120); break;
    case "yellow" : do_dmg(targ, sv, "fire", 240); break;
    case "green" : do_green(targ,sv); break;
    case "blue" : do_blue(targ,sv);break;
    case "indigo" : do_indigo(targ,sv); break;
    case "violet" : do_violet(targ,sv); break;
    default : return;
  }
  return;
}

void do_dmg (object ob, int sv, string type, int dam) {
  string burn;
  switch (type) {
    case "acid" : burn = "acidic"; break;
    case "fire" : burn = "fiery"; break;
    default : burn = "magical"; break;
  }

  if (sv) {
    dam/=2;

    tell_object(ob, "You manage to avoid some of the damage of the "+
      burn+" ray.\n");
    tell_room(environment(ob), wrap(ob->query("cap_name")+
      " manages to take only a glancing strike from the ray.\n"),
      ({ ob }) );    
  } else {
    tell_object(ob, "You are badly burned by the searing "+
      burn+" ray!\n");
    tell_room(environment(ob), wrap(ob->query("cap_name")+
      " is struck in the chest by the ray.\n"),
      ({ ob }) );  
  }

  ob->receive_damage(dam, type, caster);
  ob->set("last_attacker", caster);
  return;
}

void do_green (object ob, int sv) {
  int dam = 60;
  
  tell_object(ob, "You feel hideously sick.\nYour vision swims...\n");
  if (!sv) {
    tell_object(ob, "Your legs collapse beneath you.\n");
    tell_room(environment(ob), ob->query("cap_name")+
      " collapses suddenly.\n", ({ ob }) );
    dam = 240;
  } else {
    tell_object(ob, "You become violently ill.\n");
  }

  ob->receive_damage(dam, "poison", caster);
  ob->set("last_attacker", caster);
  return;
}

void do_blue (object ob, int sv) {
  object statue;

  if (!sv) {
    statue = clone_object(M_OBJ(statue));
    statue->set_name(ob);
    
    tell_object(ob, "You watch in horrow as you slowly transform"+
      " into solid stone!\n");
    tell_room(environment(ob), wrap(ob->query("cap_name")+
      " lets out a horrid scream as "+subjective(ob->query("gender"))+
      " turns into a marble statue!\n"), ({ ob }) );  
    statue->move(environment(caster));
    ob->move(VOID);
    ob->set("hit_points", -15);
  } else {
    tell_object(ob, "The blue ray just nicks you.\n");
    tell_room(environment(ob), "The blue ray just nicks "+
      wrap(ob->query("cap_name")+".\n"),
      ({ ob }) );  
  }
  return;
}

void do_indigo (object ob, int sv) {
  object mind;

  if (!sv) {
    mind = clone_object(M_OBJ(feeblemind_ob));
    mind->begin_spell(ob);
  } else {
    tell_object(ob, "You feel light headed for a second, but your"+
      " head soon clears.\n");
    tell_room(environment(ob), "The indigo ray just nicks "+
      wrap(ob->query("cap_name")+".\n"),
      ({ ob }) );  
  }
  return;
}

void do_violet (object ob, int sv) {
  int size = sizeof(places);

  if (!sv) {
    tell_object(ob, "The universe suddenly turns inside-out!\n"+
      "You find youself elsewhere.\n");
    tell_room(environment(ob), wrap("Time and space tear asunder, and "+
      "takes "+ob->query("cap_name")+" with it!\n"), ({ ob }) );
    ob->move(places[random(size)]);
    tell_room(ob, ob->query("cap_name")+" appears suddenly!\n",
      ({ ob }) );
  } else {
    tell_object(ob, wrap("space around you bends slightly, but "+
      "nothing else unusual happens."));
    tell_room(environment(ob), wrap("The space around "+
      ob->query("cap_name")+" warps slightly for a bit, but "+
      "nothing else happens.\n"),
      ({ ob }) );  
  }
  return;
}
string spellcraft() {
   return (@EndCraft
Prismatic Spray (Wizard  Level VII  Conjuration)

Area of Effect: One Target		Saving Throw: Special
Cost: 80 SP

When cast upon a target, a colored ray strikes the target
a saving throw applies to avoid the effects of each ray. 
**        Red - 60 points of magic damage.
**     Orange - 120 points of acid damage.
**     Yellow - 240 points of fire damage.
**      Green - Die or take 60 points of poison damage.
**       Blue - Save or be turned to stone.
**     Indigo - Save of be feebleminded.
**     Violet - Save or be sent to another plane.
EndCraft
   );
}