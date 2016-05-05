/*
**Fighter's guild
** based upon cy's and ilz code
*/


#include <daemons.h>
#include <mudlib.h>
#include <c_barbarians.h>
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>
#include "/adm/daemons/propertyd.c"
#include "/d/Outer/Sigil/sigil.h"
inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set("short", "The Grand Hall of Barbarous Intent.") ;
    set( "long", @EndText
You stand in the Grand Hall of those who wish to bash heads and drink
bad beer.

Commands are: advance, join 
EndText
    );
    set( "exits", ([
      "south" : SIGIL+"hive.c",
    ]) );
    set("class", "barbarian");
    set("group", "warrior");
    set("experience", WARRIOR_XP);
}


string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("barbarian");
    str = ({
    "$N the Peasant ($A)",
    "$N the Wanderer ($A)",
    "$N the Child of the Woods ($A)",
    "$N the Deer Meat ($A)",
    "$N the Green Tracker ($A)",
    "$N the Novice Tracker ($A)",
    "$N the Tracker ($A)",
    "$N the Veteran Tracker ($A)",
    "$N the Leader ($A)",
    "$N the Veteran Leader ($A)",
    "$N the Clanlord ($A)",
    "$N the Warrior ($A)",
    "$N the Mercenary ($A)",
    "$N the Uncivilized Myrmidon ($A)",
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
    "$N the General of Barabarism ($A)",
    "$N the Lord of Barabarism ($A)",
    "$N the Baron of Barabarism ($A)",
    "$N the King of Barabarism ($A)",
    "$N the Emperor of Barabarism ($A)",
    "$N the Clanmaster ($A)" 
  })[lvl];
    if (!str) str = "$N the Hero ($A)";

    return str;
}                


int join() {
    object badge;
    int i, t;
    if (TP->query("base_stat/strength") < 12) {
	write("You are too puny to join us!\n");
	return 0;
    }
    if (TP->query_level()){
	write ("you already have a class!\n");
	return 0;
    }

    write("A voice says, \"Welcome ...\"\n");


    badge = clone_object(BARBARIAN+"obj/furs.c");
    if (!badge) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 1;
    }
    badge->move(this_player());
    this_player()->set_skill("One Weapon Style", 1);
    this_player()->set_skill("Two Weapon Style", 1);      
    this_player()->set_skill("Shield Style", 1);            
    this_player()->set_skill("Two Handed Style", 1); 
    this_player()->set_skill("Tracking", 1); 
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

    int level, hp, max;
    object guild;
    string c, title;
    int lvl, exp;
    level = (TP->query_level("warrior"));
    if (!(this_player()->query_level("barbarian"))){
	write("You cant use this guildhall!\n");
	return 0;
    }
    write("You advance to level "+level+".\n"); 

    TP->set("base_ac", (10 - (level/3)));
    if(level%3==0) TP->add("nwp_free", 1);
    if(level%3==0) TP->add("wp_free", 1);


    hp = WAR_HP_ROLL;

    add_hp(TP, hp);
    return 1;
}
