/*
**  Pit pit fighter's guild ilz code
**  19 Jul 98  Cyanide updated it to the new prof room std.
**   5 Jul 99  Cyanide corrupted this room.
**
**  NOTE: * DO NOT COPY! *  There are now better ways to do what 
**        I did.   -Cyanide
*/

#include "/u/c/cyanide/debug.h"
#include <mudlib.h>
#include <config.h>
#include <uid.h>  
#include <skills.h>
#include <daemons.h>

// This is all skill stuff - don't touch
#define CHARACTERS ({ "a","b","c","d","e","f","g","h","i","j", \
   "k","l","m","n","o","p","q","r","s","t","u","v","w","x", \
   "y","z" })

#define PIT_FIGHTER_PATH "/d/class/warrior/pit_fighter"
#define WAR_HP_ROLL random(10)+random(10)+random(10)+3

mapping skills = ([]);
mapping min_levels = ([]);
int *v_skills, *v_minlvls;
string *k_skills, *k_minlvls;

string skills_function(string);

inherit GUILD;

void create() {
    ::create();
    seteuid(getuid());
    set( "light", 1 );
    set("short","Pit Fighter Class Hall.");
    set( "long", wrap("This is the Great Hall of Combat, where "+
	"you can join the ranks of the pit fighters, gladiators, "+
	"and combat entertainers.\nYou may choose to <join> the "+
	"class. If you are already a member, you may <list> "+
	"available skills, or <select> a proficiency.") );
    set( "exits", ([
      "east" : "/d/Prime/Central/room/road18.c",
    ]) );
    set("class", "pit fighter");
    set("group", "warrior");
    set("skills", SK_FIGHTER);
    set("min_levels", ([
      "Death Blow" : 20,
      "All Around Attack" : 15,
      "Iron Will" : 15,
    ]) );
}

void init (){
    ::init();
    add_action ("list_prof", "list");
    add_action ("learn_prof", "select");
}

// From here is all guild stuff.

string titles (object ob) {
    string str;
    int lvl;

    lvl = ob->query_level("pit fighter");
    if (lvl > 30) lvl = 30;    
    str = ({
    "$N the Civilian ($A)",                 // 0
    "$N the Cage Cleaner ($A)",
    "$N the Lucky Cage Cleaner ($A)",
    "$N the Very Lucky Cage Cleaner ($A)",
    "$N the Animal Feeder ($A)",   
    "$N the Rank Novice Fighter ($A)",      // 5
    "$N the Fighter Trainee ($A)",
    "$N the Fodder ($A)",
    "$N the Green Pit Fighter ($A)",
    "$N the Novice Pit Fighter ($A)",
    "$N the Unknown Pit Fighter ($A)",      // 10
    "$N the Pit Fighter ($A)", 
    "$N the Known Pit Fighter ($A)",
    "$N the Gladiator ($A)",
    "$N the Noted Gladiator ($A)", 
    "$N the Known Gladiator ($A)",          // 15
    "$N the Famous Gladiator ($A)",   
    "$N the Celebrated Gladiator ($A)",  
    "$N the Artist of Melee ($A)",
    "$N the Weapons Master ($A)", 
    "$N the Lord of Arms ($A)",             // 20
    "$N the Baron of Arms ($A)",
    "$N the King of Arms ($A)", 
    "$N the Emperor of Arms ($A)",   
    "$N the Master of Arms ($A)",   
    "$N the Lord of Conflict ($A)",         // 25
    "$N the Baron of Battle ($A)",
    "$N the King of Carnage ($A)",
    "$N the General of Gore ($A)", 
    "$N the Emperor of Evisceration ($A)", 
    "$N the Master of Death ($A)",          // 30
  })[lvl];

    return str;
}                


int join() {
    object scars;
    int i, t;

    if (TP->query("base_stat/strength") < 10) {
	write("You are too puny to join us!\n"+
	  "You need a strength of 10 to be a pit fighter\n");
	return 0;
    }

    write("A voice says, \"Welcome ...\"\n");

    scars = clone_object(PIT_FIGHTER_PATH+"/obj/scars.c");
    if (!scars) {
	write("\nA voice says, \"Forgive us child. You cannot join us"+
	  " now.\"\nPlease notify Cyanide.\n");
	return 0;
    }
    scars->move(this_player());
    this_player()->set_skill("One Weapon Style", 1);
    this_player()->set_skill("Two Weapon Style", 1);      
    this_player()->set_skill("Shield Style", 1);            
    this_player()->set_skill("Two Handed Style", 1); 
    this_player()->query_link()->set("level", 1 );

    i = (this_player()->query("stat/intelligence") - 11);
    t =	this_player()->query("stat/intelligence");

    if (i < 5){
	if (t < 16) i = 4;
	if (t < 14) i = 3;
	if (t < 12) i = 2;
	if (t < 9) i = 1;
    }

    this_player()->set("nwp_free", (i + 3));
    this_player()->set("wp_free", 4);

    return 1;
}

int advance() {
    int level, hp, max;

    level = (TP->query_level("warrior"));

    if (!(this_player()->query_level("pit fighter"))){
	write("You can't use this guildhall!\n") ;
	return 0;
    }

    write("You advance to level "+level+".\n"); 
    say(TPN+" advances to level "+level+".\n") ;

    if(level%3==0) TP->add("nwp_free", 1);
    if(level%3==0) TP->add("wp_free", 1);

    hp = WAR_HP_ROLL;

    add_hp(TP, hp);
    return 1;
}


// After this is all proficiency room stuff.

string skills_function(string str) {
    switch(str) {
    case "Iron Will" :
	PROPERTY_D->add_hp(TP, TP->query("base_stat/constitution") );
	break;
    }

    return "";
}

int list_prof() {
    int i, val;
    string str;

    if (query("skills")) skills = query("skills");
    if (query("min_levels")) min_levels = query("min_levels");

    if (! skills || skills==([]) ) {
	write("There are no skills being taught at this time.\n");
	return 1;
    }

    k_skills = keys(skills);
    v_skills = values(skills);

    k_minlvls = keys(min_levels);
    v_minlvls = values(min_levels);

    write("         Skills available here:\n"+
      "       --------------------------\n");

    for (i=0; i<sizeof(k_skills); i++) {
	val = member_array(k_skills[i], k_minlvls);

	if (val!=-1)
	    str = "(Minimum level: "+v_minlvls[val]+")";
	else
	    str = "";


	write(capitalize(CHARACTERS[i])+
	  sprintf(": %-18s:   %d   %s\n", 
	    capitalize(k_skills[i]), v_skills[i], str) );
    }

    write("       --------------------------\n");

    write(wrap("You have "+TP->query("nwp_free")+
	" nonweapon proficiency slots remaining."));

    return 1;
}

int learn_prof( string str ) {
    int i;
    string reason;

    if (!str || str=="" || (strlen(str) > 1) ) {
	write("Please enter the letter of the skill.\n");
	return 1;
    }

    if (TO->query("class")) {
	if (!TP->query_level("warrior")){
	    write("You cannot learn any skills here.\n");
	    return 1;
	}
    }

    if (query("skills")) skills = query("skills");
    if (query("min_levels")) min_levels = query("min_levels"); 
    k_skills = keys(skills); v_skills = values(skills);
    k_minlvls = keys(min_levels); v_minlvls = values(min_levels);

    str = lower_case(str);
    i = member_array(str, CHARACTERS);

    if ( (i == -1) || (i >= sizeof(k_skills)) ) {
	write(capitalize(str)+" is not a valid choice.\n");
	return 1;
    }

    str = k_skills[i];

    if (TP->query_skill(str)) {
	write("You already have that proficiency.\n");
	return 1;
    }

    if ((int)TP->query("nwp_free") < v_skills[i]) {
	write("You don't have enough slots to learn that skill.\n");
	return 1;
    }

    i = member_array(str, k_minlvls);
    if (i != -1) {
	int lvl;
	if (TO->query("class"))
	    lvl = TP->query_level(TO->query("class"));
	else
	    lvl = TP->query_level();

	if (lvl < v_minlvls[i]) {
	    write (wrap("You must be at least level "+
		v_minlvls[i]+" to purchase "+str+"."));
	    return 1;
	}
    }

    i = member_array(str, k_skills);
    i = v_skills[i] * -1;
    if (!i) {
	write("Error in proficiency room.\n"+
	  "Please notify Cyanide.\n");
	return 1;
    }

    reason = skills_function(str);

    if (reason && reason != "") {
	write(reason);
	return 1;
    }

    TP->set_skill(str, 1);
    TP->add("nwp_free", i);

    write(wrap("You have selected "+str+"."));

    return 1;
}

/* EOF */
