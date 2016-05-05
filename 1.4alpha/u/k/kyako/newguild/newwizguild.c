/*
**Fighter's guild
** based upon cy's and ilz code
*/




#include <daemons.h>
#include <mudlib.h>
#include "c_wizards.h"
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>
#include "/adm/daemons/propertyd.c"
inherit GUILD;

void create() {
  ::create();
  seteuid(getuid());
   set( "light", 1 );
  set("short", "Hall of the Archmages.");
  set( "long", @EndText
You enter the hall of the archmages.
This is where archmages go to gain power and spells.
Commands: <join> , <advance>, <raise (stat)>
EndText
  );
  set( "exits", ([
    "out" : "/u/k/kyako/workroom.c",
  ]) );
  set("class", "archmagi");
  set("group", "wizard");
  set("experience", WIZARD_XP);
}

void init(){
::init();
add_action("joinhero","join");
add_action("raise_stat", "raise");
}

int raise_stat(string str){
string statr;
int lvl, xp, conb, hp;

if (!str){
write ("what did you want to raise?\n");
return 1;
}
switch(str){
case "intelligence" : statr = "intelligence";break;
case "wisdom" : statr = "wisdom";break;
case "int" : statr = "intelligence";break;
case "wis" : statr = "wisdom";break;
default : statr = "not";
}

if(statr == "not"){
write("You cant raise that stat!\n");
return 1;
}

lvl = this_player()->query_level("wizard");
xp = WIZARD_XP[lvl];
xp =  (this_player()->query("experience")) - xp;
if (xp < 2000000){
write ("You have insufficient experience to do that!\n");
return 1;
}
xp =  (this_player()->query("experience"));
xp = xp - 2000000;
this_player()->set("experience", xp);
conb = PROPERTY_D->query_con_hp_bonus(this_player());
if (statr == "intelligence"){
  GUILD_D->adv_stat(this_player(), "intelligence", (this_player()->query("base_stat/intelligence")+1));
  write ("You have raised your intelligence!\n");
  return 1;
}
if (statr == "wisdom"){
  GUILD_D->adv_stat(this_player(), "wisdom", (this_player()->query("base_stat/wisdom")+1));
  write ("You have raised your wisdom!\n");
  return 1;
}
}
string titles (object ob) {
  string str;
  int lvl;

  lvl = ob->query_level("deathdealer");
     str = ({
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
      "N$ the Lord Archmage (A$)",
    })[lvl];
 
  return str;
}                


int joinhero() {
  object badge;
  string clsnme;
	int i, t;
  if (TP->query("base_stat/intelligence") < 9) {
    write("You are too stupid to join us!\n");
    return 0;
  }
/*
 if (TP->query_level()){
  write ("you already have a class!\n");
  return 0;
  }
*/

  write("A voice says, \"Welcome ...\"\n");
 badge = present("#CLASS_OBJECT#", TP);
 if (!badge){
    write("You don't even have a class!\n");
    return 0;
  }

  clsnme = badge->query("short");
if (!(clsnme == "a black bound spell book")){
    write("You have to be a mage first!\n");
    return 0;
  }
if (TP->query_level("mage") != 30){
  write("You have to be a 30th level mage first!\n");
  return 0;
  }

  badge = clone_object(DEATHDEALER+"obj/scars.c");
  if (!badge) {
    write("\nA voice says, \"Forgive us child. You cannot join us"+
      " now.\"\nPlease notify Cyanide.\n");
    return 1;
  }
  TP->set("hero", 1);
  badge->move(this_player());

//this_player()->query_link()->set("level", 1 );
  return 1;
}

int advance() {
 int level, hp, max;
 object guild;
  string c, title;
  int lvl, exp;
 

 level = (TP->query_level("warrior"));
   write("You advance to level "+level+".\n"); 

  if(level%3==0) TP->add("nwp_free", 1);
  if(level%3==0) TP->add("wp_free", 1);

  level = (130 - level);
TP->set("base_resist", ([ "fire" : level, "lightning" : level, "cold" : level, "acid" : level, "poison" : level ]) );
level = (TP->query_level("warrior") - 30);
TP->set("base_mr", (level*2));

  hp = WAR_HP_ROLL;
 
   add_hp(TP, hp);
  return 1;
}
