/*
** Rangers guild
** based upon cy's and ilz code
*/


#include <daemons.h>
#include <mudlib.h>
#include <c_rangers.h>
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>
#include "/adm/daemons/propertyd.c"
#include "/d/Outer/Sigil/sigil.h"
inherit "/d/class/priest/std/learnspell.c";
inherit GUILD;

int query_bonus_tp (object);

#define PRIEST_TP ({ 0,0,0,0,0,0,0,0,4,8,15,22,36,43,\
  50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,\
  200,210 })

void create() {
  ::create();
  seteuid(getuid());
   set( "light", 1 );
set("short","Hall of Rangers.");
  set( "long", @EndText
Rangers guild hall
Commands are: advance, join 
EndText
  );
  set( "exits", ([
"north" : SIGIL+"mainst3.c",
  ]) );
  set("class", "ranger");
  set("group", "warrior");
  set("experience", WARRIOR_XP);
}


string titles (object ob) {
  string str;
  int lvl;

  lvl = ob->query_level("ranger");
     str = ({
      "$N the Peasant ($A)",
      "$N the Recruit ($A)",
      "$N the Trainee ($A)",
      "$N the Fodder ($A)",
      "$N the Green Tracker ($A)",
      "$N the Novice Tracker ($A)",
      "$N the Tracker ($A)",
      "$N the Veteran Tracker ($A)",
      "$N the Leader ($A)",
      "$N the Veteran Leader ($A)",
      "$N the Clanlord ($A)",
      "$N the Warrior ($A)",
      "$N the Mercenary ($A)",
      "$N the Myrmidon ($A)",
      "$N the Mercenary Clanlord ($A)",
      "$N the General ($A)",
      "$N the Lord of Arms ($A)",
      "$N the Baron of Arms ($A)",
      "$N the King of Arms ($A)",
      "$N the Emperor of Arms ($A)",
      "$N the Armsmaster ($A)",
      "$N the Lord of Conflict ($A)",
      "$N the Baron of Battle ($A)",
      "$N the King of Carnage ($A)",
      "$N the Emperor of Evisceration ($A)",
      "$N the Deathmaster ($A)",
      "$N the General of War ($A)",
      "$N the Lord of War ($A)",
      "$N the Baron of War ($A)",
      "$N the King of War ($A)",
      "$N the Emperor of War ($A)",
      "$N the Warmaster ($A)" 
    })[lvl];
 
  return str;
}                


int join() {
  object badge;
	int i, t;
  if (TP->query("base_stat/strength") < 13) {
    write("You are too puny to join us!\n");
    return 0;
  }
   if (TP->query("base_stat/dexterity") < 13) {
    write("You are too clumsy to join us!\n");
    return 0;
  } if (TP->query("base_stat/constitution") < 14) {
    write("You are too frail to join us!\n");
    return 0;
  }if (TP->query("base_stat/wisdom") < 14) {
    write("You are not wise enough to join us!\n");
    return 0;
  }
if ((!(TP->query_alignment() == "neutral good"))) {
    write("You are not as good as we would like you to be!\n");
    return 0;
  }

  if (TP->query_level()){
  write ("you already have a class!\n");
  return 0;
  }

  write("A voice says, \"Welcome ...\"\n");
 

  badge = clone_object(RANGER+"obj/backpack.c");
  if (!badge) {
    write("\nA voice says, \"Forgive us child. You cannot join us"+
      " now.\"\nPlease notify Cyanide.\n");
    return 1;
  }
  badge->move(this_player());


TP->set("deity", "nature");
 this_player()->set_skill("One Weapon Style", 1);
this_player()->set_skill("Two Weapon Style", 2);      
this_player()->set_skill("Shield Style", 1);            
this_player()->set_skill("Two Handed Style", 1); 
this_player()->set_skill("Tracking", 2); 
this_player()->query_link()->set("level", 1 );
	this_player()->set("wp_free", 4);
i = (this_player()->query("stat/intelligence") - 11);
	t =	this_player()->query("stat/intelligence");
	if (i < 5){
			if (t < 16) i = 4;
			if (t < 14) i = 3;
			if (t < 12) i = 2;
			if (t < 9) i = 1;
			}

	this_player()->set("nwp_free", (i + 3));

  return 1;
}

int advance() {
 
  int level, hp, tp, max;
object guild, ob;
string c, title, spell;
  int lvl, exp;
 level = (TP->query_level("warrior"));
  if (level>30){
  write("You cant use this guildhall anymore!\n");
  return 0;
  }
  if (!(this_player()->query_level("ranger"))){
  write("You cant use this guildhall!\n");
  return 0;
  }
  write("You advance to level "+level+".\n"); 

 
  if(level%3==0) TP->add("nwp_free", 1);
  if(level%3==0) TP->add("wp_free", 1);
  tp = PRIEST_TP[level];
   tp += query_bonus_tp(TP);
set_tp(TP, tp);     

 if ((level>8) && (level%3==0)){
 spell = learn_spell();
TP->add("priest_spells", ({ spell }) );
write ("Your skills in nature allow you the use of the "+spell+" spell.\n");
}
  hp = WAR_HP_ROLL;
 
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
