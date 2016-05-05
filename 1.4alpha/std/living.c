// living.c
// Part of the new bodies project, which was launched by Watcher@TMI-2 and
// Mobydick@TMI-2.
// Based on the login code written by Buddha@TMI-2 in January 1993.
// This file was started 3-11-93 by Mobydick. All of the code that it
// inherits was pre-existing, and the appropriate headers in those files
// have been retained.
// july 97 ilz adds saves
#include <mudlib.h>

inherit BODY_BASE ;

inherit "/std/living/spells.c" ;
inherit "/std/living/skills.c" ;
inherit "/std/living/edit.c" ;
inherit "/std/object/contents" ;
inherit "/std/living/env.c";
inherit "/std/coinvalue.c" ;
inherit "/std/living/messages.c";
inherit "/std/living/volcap.c";   //Cyanide 15 July 1997
inherit "/std/living/ammo_c.c";   //Cyanide 7 Jun 1999


// This procedure returns the total number of coins the player is carrying.
// Mobydick, 10-13-92.
// Cyanide got rid of the stupid mapping of coin types and shit.

nomask int coins_carried() {
    int wealth ;

    wealth = (int)query("wealth") ;
    if (!wealth)  wealth = 0;
    return wealth ;
}


// This function returns the player's total wealth in value units.
// Mobydick, 11-5-92.
// Cyanide did the same here.  23 May 97

nomask int total_wealth() {

    int coins;

    coins = coins_carried();
    if (!coins) coins = 0 ;
    return coins ;
}

//	This function is used to check if the user is able to 
//	see anything around it.       Watcher  (01/29/93)

int query_vision() {
    mixed *contents;
    int loop;

    //	If there is no environment, you obviously can't see anything. :)

    if(!environment())  return 0;

    // 	Check to see if user has special vision capabilities,
    //	either artificial or permanent

    if(query("full_vision"))  return 1;

    //	Check to see if user is blind, or environment prevents sight

    if(query("blind") || (int)environment()->query("no_vision"))
	return 0;

    //	Check light level in the environment

    if((int)environment()->query("light") > 0)  return 1;

    contents = all_inventory(environment());

    //	Check to see if any of the environment's contents have
    //	a light source of any kind

    for(loop=0; loop<sizeof(contents); loop++)
	if(contents[loop]->check_light())  return 1;

    return 0; }

// These functions provides a mechanism for a player to be credited and
// debited with money.  Calling set or add bypasses certain checks
// and does not account for encumbrance.
// Cyanide made one coind type: "coin".   23 May 97

int credit(int amount)
{
    if(!intp(amount) || amount<=0)
	return 0;
    // if(query("capacity") < amount)
    //	return 0;
    //  add("capacity", (-(amount/10)) );      
    add("wealth",amount);
    return 1;
}

int debit(int amount)
{
    if(!intp(amount) || amount<=0)
	return 0;
    if(query("wealth") < amount)
	return 0;
    // add("capacity", (amount/10));
    add("wealth",-amount);
    return 1;
}



// here's another one for you,
// Ilz is making a function so that monsters can have classes even
// Though they got no link obj's

varargs mixed query_class (string str) {

    string *klasses;
    string klass1, klass2;
    int lvl1, lvl2;
    mapping lvls;

    if (!str){
	//we want to give him the highest lvl class
	if (this_object()->query_link()) {
	    //we have a link , it's a player
	    if (!(this_object()->query_levels2())) return 0;
	    klass1 = keys(this_object()->query_levels2())[0];
	    if (sizeof(this_object()->query_levels2())>2) klass2 = keys(this_object()->query_levels2())[1];
	    lvl1 = values(this_object()->query_levels2())[0];
	    if (sizeof(this_object()->query_levels2())>2)	lvl2 = values(this_object()->query_levels2())[1];
	    if (lvl2 > lvl1){
		return klass2;
	    }else{
		return klass1;
	    }
	}else{
	    //no link, therefore a monster.
	    klass1 = (this_object()->query("CLASS"));
	    if (!klass1) return 0;
	    return klass1;
	}
    }else{
	//we got a class, are we a member??
	if (this_object()->query_link()) {
	    //alas a player

	    lvls = this_object()->query_levels2();
	    if (lvls)
		klasses = (keys(lvls));
	    else
		klasses = ({ "none" });

	    lvl1 = (member_array(str, klasses));
	    if (lvl1 == -1) {
		return 0;
	    }else{
		return 1;
	    }
	}else{
	    //no link, a monster
	    if (str == (this_object()->query("CLASS")) ){
		return 1;
	    }else{
		return 0;
	    }
	}
    }
}

/* EOF */
