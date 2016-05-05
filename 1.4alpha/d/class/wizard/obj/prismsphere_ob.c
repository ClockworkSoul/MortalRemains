/*
**ILZ
*/

#include <m_spells.h>
#include <magic.h>
#include <mudlib.h>
#include <config.h>

inherit SPELL;
inherit OBJECT;

void do_color(string , object , int );
void do_dmg (object , int , string , int );
void do_green (object , int );
void do_blue (object , int );
void do_indigo (object , int );
void do_violet (object , int );

int hits_left, level;

void create() {
    seteuid(getuid());
    set("enchantment", OVERWHELMING);
    set("schools", ({ "abjuration", "conjuration" }) );
    set("id", ({ "#PRISMATIC_SPHERE#", "#REFLEXIVE_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

void init(){
    add_action("kill", "kill");
    add_action("go", "go");
}

int go(string str){
    call_out("remove", 1);
    return 0;
}

int start_spell(object caster) {
    set("level", caster->query_level());
    tell_object(caster, "You are suddenly surrounded by a prismatic sphere.\n");
    tell_room(environment(caster), caster->query("cap_name") +
      " is suddenly surrounded by a prismatic sphere.\n", ({ caster }) );
    set("extra_look", "$N is surrounded by a prismatic sphere.\n");
    hits_left = 7;
    call_out("remove", ((caster->query_level() * 10) ));
  
    return 1;
}

int reflex(int damage, string type, object ob, int weap) {
    string done, color;
    int sv;

    sv = -((level - 20)/2);
    if (sv>0) sv = 0;
    if (sv < -6) sv = -6;
    sv = ob->save_throw(sv);

    if (!weap){
	tell_object(environment(), "You just cackle with glee as your prismatic sphere protects you!\n");
	tell_room(environment(environment()), environment()->query("cap_name")+
	  " cackle's  with glee as the prismatic sphere protects them.!\n", ({ environment() }) );
	return 0;
    }

    if (hits_left && weap) {
	switch (hits_left){
	case 7 : do_color("red", ob, sv);break;
	case 6 : do_color("orange", ob, sv);break;
	case 5 : do_color("yellow", ob, sv);break;
	case 4 : do_color("green", ob, sv);break;
	case 3 : do_color("blue", ob, sv);break;
	case 2 : do_color("indigo", ob, sv);break;
	case 1 : do_color("violet", ob, sv);break;
	}
	hits_left--;
	if (!hits_left) remove();

	return 0;    
    }

    return damage;
}

int remove() {
    object caster = environment(this_object());
    if (environment()) caster = environment();
    if ((caster) && living(caster)) {
	tell_object(caster, "Your prismatic sphere dissapears.\n");
	tell_room(environment(caster), caster->query("cap_name") +
	  "'s prismatic sphere dissapears.\n", ({ caster }) );
    }
    ::remove();
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
    object caster = environment(this_object());
    switch (type) {
    case "acid" : burn = "acidic"; break;
    case "fire" : burn = "fiery"; break;
    default : burn = "magical"; break;
    }

    if (sv) {
	dam/=2;

	tell_object(ob, "You manage to avoid some of the damage of the "+
	  burn+" layer.\n");
	tell_room(environment(ob), wrap(ob->query("cap_name")+
	    " manages to take only a glancing strike from the "+burn+" layer.\n"),
	  ({ ob }) );    
    } else {
	tell_object(ob, "You are badly burned by the searing "+
	  burn+" layer!\n");
	tell_room(environment(ob), wrap(ob->query("cap_name")+
	    " is burned by the "+burn+" layer.\n"),
	  ({ ob }) );  
    }

    ob->receive_damage(dam, type, caster);
    ob->set("last_attacker", caster);
    return;
}

void do_green (object ob, int sv) {
    int dam = 60;
    object caster = environment(this_object());

    tell_object(ob, "You feel hideously sick.\nYour vision swims...\n");
    if (!sv) {
	tell_object(ob, "Your legs collapse beneath you.\n");
	tell_room(environment(ob), ob->query("cap_name")+
	  " collapses suddenly.\n", ({ ob }) );
	dam = 120;
    } else {
	tell_object(ob, "You become violently ill.\n");
    }

    ob->receive_damage(dam, "poison", caster);
    ob->set("last_attacker", caster);
    return;
}

void do_blue (object ob, int sv) {
    object statue;
    object caster = environment(this_object());


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
	tell_object(ob, "The blue layer just nicks you.\n");
	tell_room(environment(ob), "The blue layer just nicks "+
	  wrap(ob->query("cap_name")+".\n"),
	  ({ ob }) );  
    }
    return;
}

void do_indigo (object ob, int sv) {
    object mind;
    object caster = environment(this_object());

    if (!sv) {
	mind = clone_object(M_OBJ(feeblemind_ob));
	mind->begin_spell(ob);
    } else {
	tell_object(ob, "You feel light headed for a second, but your"+
	  " head soon clears.\n");
	tell_room(environment(ob), "The indigo layer just nicks "+
	  wrap(ob->query("cap_name")+".\n"),
	  ({ ob }) );  
    }
    return;
}

void do_violet (object ob, int sv) {

    object caster = environment(this_object());
    object *places = ({
    "/d/Ancients/rooms/post_office",
    "/d/Ancients/rooms/bugroom",
    "/d/Ancients/rooms/wizrm",
    "/d/std/void",
    "/d/Outer/Baator/avernus/ave1.c",
  });

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

int kill(string str) {
    write("You can't simply attack from inside a prismatic sphere.\n"+
      "Try casting offensive spells instead.\n");
    return 1;
}

/* EOF */
