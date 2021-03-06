/*
** Knight's guild
** based upon cy's and ilz code
**   13 May 98  Cyanide fixed Ilzarion's FUCKING ABORTION.
*/

inherit GUILD;
inherit "/d/class/priest/std/learnspell.c";

#define ALLOWED_RACES ({ "dwarf", "human", "elf", "half-elf" })

#include "/d/Outer/Sigil/sigil.h"
#include "../c_knight.h"
#include <daemons.h>
#include <mudlib.h>
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>

int query_bonus_tp (object);

#define PRIEST_TP ({ 0, 0, 0, 0, 0, 8, 16, 28, 32, 44, 60, 104, 152, 220,\
252, 332, 370, 385, 400, 415, 435, 455, 475, 495, 515, 535, 555, \
   575, 595, 615, 635 })

void create() {
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set("short","Hall of Knights.");
    set( "long", @EndText
You have entered the Knights Stronghold. Before you
is a long hall where at the far end is a table with
an old man sitting behind it wearing regal armor. Sounds of
men fighting and learning echo throught the halls.
Commands are: advance, join 
EndText
    );
    set( "exits", ([
      "north" : "/d/Outer/Sigil/mainst7.c",
    ]) );
    set("class", "knight");
    set("group", "warrior");
    call_other("/d/class/warrior/knight/obj/k_board", "dummy"); 
}


string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("knight");
     if (lvl > 31) lvl = 31;
    str = ({
    "$N the Squire's Squire ($A)",
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
    } 

    if (TP->query("base_stat/constitution") < 10) {
	write("You are too frail to join us!\n");
	return 0;
    } 


    if ((!(TP->query_alignment() == "lawful good"))) {
	write("You are not as good and honorable as we would "+
	  "like you to be!\n");
	return 0;
    }

    if (TP->query_level()){
	write ("You already have a class!\n");
	return 0;
    }

    write("A voice says, \"Welcome ...\"\n");
    write("The General calls for a fellow knight.\n");
    write("Mutters something to the knight.\n");
    write("The knight rushes of only to come back with a Suit of Platemail.\n");
    write("A voice says, \"Take care of this armor, son, and "+
      "wear it with pride.\"\n");

    badge = clone_object(KNIGHT+"obj/solplate.c");
    if (!badge) {
	write("\nA voice says, \"Sorry trooper. You are not permitted to join"+
	  " now.\"\nPlease notify Darkangel.\n");
	return 1;
    }
    badge->move(this_player());

    TP->set("deity", "Paladine");

    this_player()->set_skill("One Weapon Style", 1);
    this_player()->set_skill("Two Weapon Style", 1);
    this_player()->set_skill("Shield Style", 1);
    this_player()->set_skill("Two Handed Style", 1);
    this_player()->set("wp_free", 3);
    i = (this_player()->query("stat/intelligence") - 11);
    t =	this_player()->query("stat/intelligence");

    if (i < 5){
	switch(t) {
	case 1..8 : i = 1; break;
	case 9..11 : i = 2; break;
	case 12..13 : i = 3; break;
	case 14..15 : i = 4; break;
	default : i = 3;
	}
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
    if (level == 4) TP->add("priest_spells", ({ "bless" }) );
    if (level == 6) TP->add("priest_spells", ({ "curelt" }) );
    if (level == 8) TP->add("priest_spells", ({ "battlefate" }) );
    if (level == 10) TP->add("priest_spells", ({ "aid" }) );
    if (level == 12) TP->add("priest_spells", ({ "bodyblades" }) );
    if (level == 14) TP->add("priest_spells", ({ "prayer" }) );
    if (level == 16) TP->add("priest_spells", ({ "coldprot" }) );
    if (level == 18) TP->add("priest_spells", ({ "fireprot" }) );
    if (level == 21) TP->add("priest_spells", ({ "necroprot" }) );
    if (level == 22) TP->add("priest_spells", ({ "cureser" }) );
    if(level == 23) TP->add("priest_spells", ({ "stonestrength" }) );
    if (level == 24) TP->add("priest_spells", ({ "venomprot" }) );
    if (level == 27) TP->add("priest_spells", ({ "curecrit" }) );
    if (level == 29) TP->add("priest_spells", ({ "recall" }) );
    if (level == 28) TP->add("priest_spells", ({ "bladebarrier" }) );
    if (level == 30) TP->add("priest_spells", ({ "entropyshield" }) );
    if (level == 35) TP->add("priest_spells", ({ "greaterheal" }) );


    hp = WAR_HP_ROLL;

    add_hp(TP, hp);
    return 1;
}

int query_bonus_tp (object ob) {
    int brains = ob->query("base_stat/wisdom"), sp;

    switch(brains) {
    case  0..11 : sp = 5; break;
    case 12..13 : sp = 6; break;
    case 14..15 : sp = 8; break;
    case 16 : sp = 9; break;
    case 17 : sp = 10; break;
    case 18 : sp = 11; break;
    case 19 : sp = 12; break;
    default : sp = 14;
    }

    return sp;
}
