/*
** Rangers guild
** based upon cy's and ilz code
*/


#include <daemons.h>
#include <mudlib.h>
#include <config.h>
#include </u/d/darkgoth/private/knight/c_knight.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>
#include "/adm/daemons/propertyd.c"
#include "/d/Outer/Sigil/sigil.h"
inherit "/d/class/priest/std/learnspell.c";
inherit GUILD;

int query_bonus_tp (object);

#define PRIEST_TP ({ 0, 0, 0, 0, 0, 2, 4, 8, 16, 28, 32, 44, 60, 104, 152,\
  220, 252, 332, 368, 378, 388, 398, 408, 418, 428, 438, 448, 458, 468, 478, 488 })

void create() {
  ::create();
  seteuid(getuid());
   set( "light", 1 );
set("short","Hall of Knights.");
  set( "long", @EndText
Knights of Solamnia guild hall
Commands are: advance, join 
EndText
  );
  set( "exits", ([
"north" : SIGIL+"mainst3.c",
  ]) );
  set("class", "knight");
  set("group", "warrior");
  set("experience", WARRIOR_XP);
}


string titles (object ob) {
  string str;
  int lvl;

lvl = ob->query_level("knight");
     str = ({
      "$N the Squire of Crown ($A)",
      "$N the Defender of Crown ($A)",
      "$N the Knight of Crown ($A)",
      "$N the Scepter Knight ($A)",
      "$N the Shield Knight ($A)",
      "$N the Lord of Shields ($A)",
      "$N the Master Warrior ($A)",
      "$N the Lord of Crown ($A)",
      "$N the Lord Warrior ($A)",
      "$N the High Warrior ($A)",
      "$N the Knight of Swords ($A)",
      "$N the Blade Knight ($A)",
      "$N the Knight Clerist ($A)",
      "$N the Abott of Swords ($A)",
      "$N the Elder of Swords ($A)",
      "$N the Master of Swords ($A)",
      "$N the Lord of Swords ($A)",
      "$N the Master Clerist ($A)",
      "$N the Lord Clerist ($A)",
      "$N the High Clerist ($A)",
      "$N the Knight of Tears ($A)",
      "$N the Knight of Heart ($A)",
      "$N the Knight of Roses ($A)",
      "$N the Keeper of Roses ($A)",
      "$N the Master of Roses ($A)",
      "$N the ArchKnight ($A)",
      "$N the Lord of Roses ($A)",
      "$N the Master of Justice ($A)",
      "$N the Lord of Justice ($A)",
      "$N the High Justice ($A)"
    })[lvl];
 
  return str;
}                


int join() {
  object badge;
	int i, t;
  if (TP->query("base_stat/strength") < 12) {
    write("You are too puny to join us!\n");
    return 0;
  }
   if (TP->query("base_stat/dexterity") < 9) {
    write("You are too clumsy to join us!\n");
    return 0;
  } if (TP->query("base_stat/constitution") < 10) {
    write("You are too frail to join us!\n");
    return 0;
  } if (TP->query("base_stat/intelligence") < 9) {
   write("You are not smart enough to join us!\n");
    return 0;
 }if (TP->query("base_stat/wisdom") < 12) {
    write("You are not wise enough to join us!\n");
    return 0;
  }
 if ((!(TP->query_alignment() == "lawful good"))) {
    write("You are not as good and honorable as we would like you to be!\n");
    return 0;
  }

  if (TP->query_level()){
  write ("you already have a class!\n");
  return 0;
  }

  write("A voice says, \"Welcome ...\"\n");
 

badge = clone_object(KNIGHT+"obj/solplate.c");
  if (!badge) {
   write("\nA voice says, \"Sorry trooper. You are not permitted to join"+
     " now.\"\nPlease notify Darkgoth.\n");
    return 1;
  }
  badge->move(this_player());


TP->set("deity", "Paladine");
this_player()->query_link()->set("level", 1);
        this_player()->set("wp_free", 3);
i = (this_player()->query("stat/intelligence") - 11);
	t =	this_player()->query("stat/intelligence");
	if (i < 5){
			if (t < 16) i = 4;
			if (t < 14) i = 3;
			if (t < 12) i = 2;
			if (t < 9) i = 1;
			}

        this_player()->set("nwp_free", (i + 2));

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
  if (!(this_player()->query_level("knight"))){
  write("You cant use this guildhall!\n");
  return 0;
  }
  write("You advance to level "+level+".\n"); 

 
  
  if (level>19){
   if(level%2==0) TP->add("nwp_free", 1);
   }else{
    if(level%3==0) TP->add("nwp_free", 1);
    }
   if(level%3==0) TP->add("wp_free", 1);
  tp = PRIEST_TP[level];
   tp += query_bonus_tp(TP);
set_tp(TP, tp);     
if (level == 5) TP->add("priest_spells", ({ "bless" }) );
 if ((level>10) && (level%3==0)){
 spell = learn_spell();
TP->add("priest_spells", ({ spell }) );
write ("Your devotion to Paladine allows you the use of the "+spell+" spell.\n");
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
