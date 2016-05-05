
// This file is part of the TMI distribution mudlib.

// Please include this header if you use the code here.
// Originally written by Brian Leet.
// Adapted by Sulam (12-13-91)
// Help added by Brian (1/28/92)  *smirk*
// Better messages added by Brian (2/5/92)
// Money functions and comments added by Mobydick@TMI-II  (8-24-92)
// Prevent_get added by Watcher@TMI (3/5/93)
//
// 28 May 97  Cyanide converted to the 1 credit system. Its 
//            better and easier.
// 08 Apr 98  Cyanide steamlined this cmd. It was buggy and 
//            inefficient; much less so now.
// 07 Jun 99  Cyanide adds support for ammunition types.

#include "/u/c/cyanide/debug.h"
#include <mudlib.h>
#include <money.h>
#include <move.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: get [object | all] <from [container]>\n"

int get_ob(object);

int cmd_get( string str ) {
    object ob, *inv, ob2, *all;
    int res, i, number, is_money;
    string word, tmp, type;
    int ammount, counter;

    notify_fail("Get what?\n");
    if(!str || str == "")  return 0;

    /*
      this_player()-> block_attack( 2 );
    */

    if(!this_player()->query("vision")) {
	notify_fail("Get what?  You can't see a thing!\n");
	return 0; }


    if (str == "all credit" || str == "all credits" || 
      str == "all gold") {
	ob = present("credits", environment(this_player()) ); 
	if (ob) {
	    write("You take "+ob->query("short")+".\n");
	    say(this_player()->query("cap_name")+" takes "+
	      ob->query("short")+".\n");

	    ob->move(this_player());   

	    return 1;
	} else {
	    write ("There are credits here.\n");
	    return 1;
	}
    }

    if (str == "all ammo" || str == "all shells" || 
      str == "all ammunition" || str == "all rounds") {
	ob = present("ammo", environment(this_player()) ); 
	if (ob) {
	    write("You take "+ob->query("short")+".\n");
	    say(this_player()->query("cap_name")+" takes "+
	      ob->query("short")+".\n");

	    ob->move(this_player());   

	    return 1;
	} else {
	    write ("There is no ammunition here.\n");
	    return 1;
	}
    }


    /* Check for form "get 30 9mm rounds"  */
    if( sscanf( str, "%d %s %s", ammount, tmp, type ) != 3 )

	/* Check for form "get 30 credits" */
	if( sscanf( str, "%d %s", ammount, type ) != 2 ) {

	    /* Check for command "get all" */  
	    if( str == "all" ) {
		if (environment(this_player())) {
		    inv = all_inventory( environment( this_player() ) );
		    inv = filter_array(inv, "filter_short", this_object());
		    all = filter_array(inv, "filter_get", this_object());
		}

		if(sizeof(inv) <= 1 || sizeof(all) == 1) {
		    notify_fail("There is nothing here for you to get.\n");
		    return 0;
		}

		for( i = 0; i <sizeof( inv ); i++ ) {

		    if (living(inv[i])) continue ;
		    if((int)inv[i]->query("prevent_get")) {
			write("You can't get the " + 
			  (string)inv[i]->query("short") + ".\n");
			continue;
		    }

		    counter += get_ob(inv[i]);
		}

		if (!counter) write("There is nothing here to take!\n");
		return 1;
	    }

	    /* Check for get all <item> */
	    if (sscanf(str, "all %s", type) == 1) {
		if (environment(this_player())) {
		    inv = all_inventory( environment(this_player() ));
		    inv = filter_array(inv, "filter_short", this_object());
		    all = filter_array(inv, "filter_get", this_object());
		}

		if (sizeof(inv) <= 1 || sizeof(all) == 1) {
		    notify_fail("There is nothing here for you to get.\n");
		    return 0;
		}

		for (i=0;i<sizeof(inv);i++) {
		    if (!inv[i]->id(type)) continue;
		    if (inv[i]->query("prevent_get")) continue;
		    counter+=get_ob(inv[i]);
		}

		if (!counter) write("There is nothing here to be taken!\n");
		return 1;
	    }

	    /* Assume he's trying to pick up a single object. */
	    ob = environment( this_player() );
	    if (!ob) {
		notify_fail("You can't take anything in the void!\n");
		return 0;
	    }
	    ob = present( str, ob );
	    if( !ob ) {
		if( ( int ) environment( this_player() )-> id( str ) ) {
		    notify_fail( "You can't take that!\n" );
		    return 0;
		}
		notify_fail("There is no such object here to get.\n");
		return 0;
	    }
	    get_ob(ob);
	    return 1;
	}

	// If we get here, it means we tried to "get 20 credits"
	// or "get 20 rounds".
    if( ammount < 1 ) {
	write( "You can only take positive amounts of "+type+".\n" );
	return 1;
    }

    // This adds support for ammo types.
    if (tmp) type = tmp + " " + type;

    // Both credits and ammo use the query_number() function.
    ob = present( type, environment( this_player() ) );

    if( !ob || ob-> query_number() <ammount ) {
	write( "I don't see that many here.\n" );
	return 1;
    }

    // Split the pile of credits or ammo into two, the part taken 
    // and the part left behind.

    number = ob-> query_number();

    if (ob->query("money")) {
	if( ammount == 1 ) word = "credit"; else word = "credits";
	write( "You take " + ammount + " " + word + ".\n" );
	TP->credit(ammount);
    } else {    
	ob2 = clone_object( "/std/ammo.c" );
	number = ob-> query_number();
	type = ob->query_type();
	ob2-> set_type( type );
	ob2-> set_number( ammount );
	res = ( int ) ob2-> move( this_player() );
	if( ammount == 1 ) word = "shell"; else word = "shells";
	write( "You take " + ammount + " " + type + " " + word + ".\n" );
    }

    ob-> set_number( number - ammount );
    say( this_player()-> query( "cap_name" ) + " takes some " + type + ".\n" );

    return 1;
}

int get_ob(object ob) {
    int res, is_money = 0, number = 0;
    string word, short;

    if (ob->query("money")) {
	is_money = 1; 
	number = ob->query_number();
    }

    if((int)ob->query("prevent_get")) {
	write("You can't get that object.\n");
	return 1; 
    }

    short = (string) ob->query("short");
    res = ( int ) ob-> move( this_player() ); 

    switch (res) {
    case MOVE_OK :
	if( number ) {
	    if( number == 1 ) 
		word = "credit"; 
	    else 
		word = "credits";

	    write( "You take " + number + " " + word + ".\n" );
	    say(this_player()->query("cap_name")+" takes "
	      +number+" "+word+".\n" );
	} else {
	    if(!short) short = "something";
	    write("You take " + short + ".\n") ;
	    say( this_player()->query("cap_name") + " takes " +
	      short + ".\n") ;
	}
	return 1;
	break;
    case MOVE_NOT_ALLOWED :
	write( ob->query("short")+": You can't take that.\n" );
	break;
    case MOVE_NO_ROOM :
	write( "You don't have enough room to carry that.\n" );
	break;
    case MOVE_TOO_HEAVY :
	write( "It is so heavy you cannot pick it up!\n" );
	break;
    }

    return 0;
}

static int filter_short(object obj) {  return (obj->query("short") != 0); }

static int filter_get(object obj) {  return !(obj->query("prevent_get"));  }

string help() {

    return( SYNTAX + "\n" +
      "This command will have your character try to pick up the\n" +
      "item specified, or if all is typed, it will make your\n" +
      "character try to pick up everything in the room.\n"+
      "\nSee also: put, drop\n") ;
}
/* EOF */
