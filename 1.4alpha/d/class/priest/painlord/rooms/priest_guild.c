/*
**Priests of tempus (used cy's mages guild as base.) -ilz
*/

#define FIND find_player("ilzarion")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

// This is a temporary array of priestTP's until I feel like making
// the real priest TP list...
#define PRIEST_TP ({ 0,4,8,15,25,40,55,70,90,125,160,200,240,290,\
  340,400,460,530,600,675,750,825,900,975,1050,1125,1200,1275,1350,\
  1425,1500 })

#include <daemons.h>
#include <mudlib.h>
#include <c_priests.h>
int query_bonus_tp (object);
inherit GUILD;
string *SPELL_LIST = ({
  ({ "light" }),          
  ({ "cure_light"}),             
  ({  }),               
  ({  }),           
  ({ "cure_moderate" }),                    
  ({  }),                        
  ({  }),                      
  ({  }),                              
  ({ "cure_serious" }),                              
  ({  }),                
  ({  }),          
  ({  }),         
  ({ "cure_critical" }),    
  ({  }),     
  ({  }),                 
  ({  }),                 
  ({ "heal" }),           
  ({  }),                 
  ({  }),                
  ({  }),         
  ({  }),         
  ({  }),          
  ({  }),       
  ({  }),                
  ({  }),          
  ({  }),          
  ({  }),         
  ({  }),   
  ({  }),      
  ({  }),     
  ({  }) });
void create() {
  ::create();
  seteuid(getuid());
  set("short", "The Guild of Loviatar");
  set ("long", "An unfinished guildhall.\n");
  set("light", 1);
  set("class", "priest");
  set("group", "priest");
  set("experience", PRIEST_XP);
set ("exits", ([ "sigil" : "/d/Outer/Sigil/clericguild.c" ]) );
}



string titles (object ob) {
  string str, diety;
  int lvl;

  diety = ("Loviatar");
  lvl = ob->query_level("priest");
     str = ({
      "$N the blah of "+diety+" ($A)",
      "$N the Worshiper of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
     "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Stormlord of "+diety+" ($A)",
     "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
     "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
      "$N the Painlord of "+diety+" ($A)",
    })[lvl];
  
  return str;
}                




int join() {
  object robes;
int tp, brains;
  if (TP->query("base_stat/wisdom") < 15) {
    write("You are not wise enough to be a member!\n");
    return 0;
  }
 if (TP->query("base_stat/constitution") < 15) {
    write("You are not hardy enough for us!\n");
    return 0;
  }

   if (!(TP->query_alignment() == "lawful evil")){
    write("You are not lawful and evil enough for us!\n");
    return 0;
  }
  write("A voice says, \"Welcome child...\"\n");
  write("The air shimmers, and a pair of long black gloves appears in your hands.\n");
  write("A voice says, \"Take care of this gift, child, and it"+
    " will serve you well.\"\n");

 tp = PRIEST_TP[1];
  tp += query_bonus_tp(TP);
set_tp(TP, tp);

  TP->set_skill("One Weapon Style", 1);
  TP->set_skill("Two Handed Style", 1);
  TP->set_skill("Shield Style", 1);
 brains = this_player()->query("stat/intelligence");
  switch (brains) {
    case 0..8 : brains = 1; break;
    case 9..11 : brains = 2; break;
    case 12..13 : brains = 3; break;
    case 14..15 : brains = 4; break;
    default : brains-=11; break;
  }

  TP->set("nwp_free", (4 + brains)); 
  TP->set("wp_free", 2);

  TP->set("deity", "loviatar");
  robes = clone_object(LOVIATAR+"obj/gloves.c");
  if (!robes) {
    write("\nA voice says, \"Forgive us child. You cannot join us"+
      " now.\"\nPlease notify Cyanide.\n");
    return 1;
  }
 robes->move(this_player());
  return 1;
}

int advance() {
  int level, hp, max;

  level = (TP->query_level("priest"));
  write("You advance to level "+level+".\n");

  if(level%3==0) TP->add("nwp_free", 1);
  if(level%4==0) TP->add("wp_free", 1);

   hp = query_bonus_tp(TP);
  hp += PRIEST_TP[level];
  set_tp (TP, hp);

  
TP->add("priest_spells", SPELL_LIST[level - 1]);
  hp = PRIEST_HP_ROLL;
   add_hp(TP, hp);
   return 1;
}
int query_bonus_tp (object ob) {
  int brains = ob->query("base_stat/wisdom"), sp;

  switch(brains) {
    case  0..11 : sp = 2; break;
    case 12..13 : sp = 3; break;
    case 14..15 : sp = 4; break;
    case 16 : sp = 5; break;
    case 17 : sp = 6; break;
    case 18 : sp = 7; break;
    case 19 : sp = 8; break;
    default : sp = 9;
  }

  return sp;
}
