/*
** Coded by Cyanide, 7 Feb 2000
** Based on ideas by Blood.
*/

#include <move.h>
#include <mudlib.h>
#include <money.h>

#define HOLE_PATH "/u/c/cyanide/working/holeroom.c"

inherit CONTAINER;

object holeroom;

void create() {
    ::create();
    set("short", "a portable hole");
    set_open_long( @EndText
This is simply a hole in the ground, though it looks somehow... 
artificial. If you wished, you could put something into the hole, or
'enter' it just as easily.
EndText
    );
    set_closed_long( "It appears to be a black piece of some kind of fabric.\n" );
    set("id", ({ "hole", "portable hole" }) );
    set("volume", 9999999);
    set("capacity", 9999999);
}


void init()
{
   add_action("get_from","get");
   add_action("put_into","put");
   add_action("enter_func", "enter");
}

object myroom() {
    if (!holeroom)
	holeroom = find_object_or_load(HOLE_PATH);

    return holeroom;
}


int enter_func(string hole) {
    if (query_is_closed()) return 0;

    write("You climb into the portable hole.\n");
    say(TPN+" climbs into the portable hole.\n");

    TP->move_player( myroom(), "SNEAK" );

    message("movement", TPN+" climb in through the hole in the wall.\n",
        all_inventory(myroom()), TP);

    return 1;
}

int absorb ( object ob ) {
    if (myroom())
	return ob->move(myroom());
}


int receive_object( object ob ) {

    call_out("absorb", 0, ob);

    return ::receive_object(ob);
}


string query_long(string str)
{
	object *inv;
	int i;
	mixed desc;

	if (environment(TO)->query_room()) {
	    desc = open_long_desc ;

		inv = all_inventory( myroom() );
		if (sizeof(inv) > 0 ) {
			desc += "It contains:\n";
			for(i=0;i<sizeof(inv);i++)
				desc += "  "+ (string)inv[i]->query("short")+"\n";
	    }
	} else {
	    desc = closed_long_desc ;
	}

	return desc;
}

int move ( mixed dest ) {
    int val;

    val = ::move( dest );

    if (val == MOVE_OK) {    
        if (objectp(dest) && (object)dest->query_room()) {
            tell_room(dest, "Suddenly, the cloth folds into the "+
                "ground, becoming a hole!\n");  
            message("info", "Suddenly, a hole opens up, leading out!\n",
            all_inventory(myroom()), ({}) );
            myroom()->set("exits", ([
                "out" : base_name(dest)
            ]) ); 
            if (query_is_closed()) toggle_closed();
        } else {
            if (!query_is_closed()) toggle_closed();
            if (myroom()->query("exits")) {
                myroom()->delete("exits");
                message("info", "The only exit out suddenly closes.\n",
                    all_inventory(myroom()), ({}) );
            }
        }
    }

    return val;    
}

int put_into(string str) {
    int i;

    i = ::put_into(str);

    set("capacity", 99999);
    return i;
}

int get_from(string str) {
    int res, i, num, has, mass ;
    object ths, tht, *contents;
    object ob2 ;
    string this, that, word ;

    if (!str) {    
	notify_fail ("Get what from what?\n") ;
	return 0 ;
    }

    //  Check to see if the user can see what they are doing.

    if(!TP->query("vision")) {    
	write("Get what from where?  You can't see anything!\n");
	return 1; 
    }

    // Check for the form "get 20 credits from sack".
    if (sscanf(str,"%d %s from %s",num,this,that)==3) {

	tht = present(that, TP) ;

	if (!tht) tht = present(that,environment(TP)) ;

	if (!tht) {    
	    notify_fail ("Get what from what?\n") ;
	    return 0 ;
	}    

	// Is it closed?
	if (tht->receive_objects()) {    
	    notify_fail ("That container is closed.\n") ;
	    return 0 ;
	}

	if((int)tht->query("prevent_get")) {    
	    notify_fail("You can't get that object.\n");
	    return 0; 
	}    

	if (!tht) {    
	    notify_fail ("I don't see a "+that+" here.\n") ;
	    return 0 ;
	}

	if (tht!=this_object()) return 0 ;

	ths = present(this, myroom()) ;

	if (!ths) {    
	    notify_fail ("There aren't any credits in "+that+".\n") ;
	    return 0 ;
	}

	if (ths->query_number()<num) {    
	    notify_fail ("There aren't that many credits in "+that+".\n") ;
	    return 0 ;
	}

	ob2 = clone_object(COINS) ;
	ob2->set_type(ths->query_type()) ;
	ob2->set_number(num) ;

	if (environment(this_object())==TP)
	    ob2->move(TP) ;

	if (res!=MOVE_OK) {    
	    notify_fail ("You don't feel good about doing that. "+
	      "Tell a wizard.\n") ;
	    return 0 ;
	}

	ths->set_number((int)ths->query_number()-num) ;
	if (num==1) word="credit" ; else word = "credits" ;
	write ("You get "+num+" "+word+" from "+that+".\n") ;
	say (TP->query("cap_name")+" gets "+num+" "+word+
	  " from "+that+".\n") ;

	return 1 ;
    }

    // Check for the form "get thingy from sack".
    // This may or may not be choking on money. I hope not...
    if (stringp(str) && sscanf(str,"%s from %s",this,that) == 2) {        
	if (present(that,TP) ||

	  present(that, environment(TP))) {    
	    tht = present(that);
	    if (tht!=this_object()) return 0 ;

	    if (tht->receive_objects()) {
		if (this != "all") {
		    ths = present(this, myroom());
		    if (!ths) {    
			notify_fail("There is no "+this+" in the "+that+".\n") ;
			return 0 ;
		    }

		    if((int)ths->query("prevent_get")) {    
			notify_fail("You can't get that object.\n");
			return 0; 
		    }

		    if (ths) {    
			mass = ths->query("mass") ;
			word = ths->query("short") ;

			// When the player removes the object, the container gets lighter, so we
			// need to increase the player's capacity.
			if (environment(this_object())==TP)
			    TP->set("capacity",(int)TP->query("capacity")+mass);

			res = (int)ths->move(TP);    
			if (res == MOVE_OK)     {
			    set ("mass", 0) ;

			    write ("You get "+word+" from "+tht->query("short")+".\n");
			    say(TP->query("cap_name")+" gets "+
			      word + " from "+tht->query("short")+".\n") ;
			    return 1;
			}
			if (res == MOVE_NOT_ALLOWED) 
			    notify_fail("You are not allowed to do that...\n");

			if (res == MOVE_NO_ROOM)
			    notify_fail("There is not enough room to do that...\n");

			// This should never happen.
			if (res == MOVE_TOO_HEAVY)
			    notify_fail ("It is too heavy.\n") ;

			if (environment(this_object())==TP)
			    TP->set("capacity",(int)TP->query("capacity")-mass) ;
			return 0;
		    }       
		    notify_fail(capitalize(this)+" is not in "+
		        tht->query("short")+".\n");

		    return 0;
		}

		// If we got here, it means we're doing a "get all from container".
		contents = all_inventory(myroom());
		if (sizeof(contents) > 0 ) {                               
		    for (i=0;i<sizeof(contents);i++) {                    
			ths = contents[i];

			if((int)ths->query("prevent_get"))
			    continue;

			mass = contents[i]->query("mass") ;
			word = contents[i]->query("short") ;

			// When the object is removed from the container, if the 
			// player is holding the container then his capacity goes up.

			if (environment(this_object())==TP)
			    TP->set("capacity", (int)TP->query("capacity")+mass) ;
			res = (int)ths->move(TP);
			if (res == MOVE_OK) {    
			    // Change the mass of the container.
			    set ("mass", query("mass")-mass) ;
			    write ("You take "+word+" from "+tht->query("short")+".\n") ;
			    say(TP->query("cap_name")+" gets "+
			      word+" from "+tht->query("short")+".\n") ;
			}
			if (res == MOVE_NO_ROOM) {    
			    write("Can't carry "+ths->query("short")+".\n");
			    if (environment(this_object())==TP)
				TP->set("capacity", (int)TP->query("capacity")+mass) ;
			}
		    }                
		    return 1;
		}
		notify_fail("Nothing in "+tht->query("short")+".\n");
		return 0;
	    }
	    notify_fail(capitalize(this)+" is not here.\n");
	    return 0;
	}
	notify_fail(capitalize(that)+" is closed.\n");
	return 0;
    }
    return 0;
}

int open_container() {
    notify_fail("You cannot simply open that.\n");
    return 0; 
}

int close_container() {
    notify_fail("You cannot simply close that.\n");
    return 0; 
}

/* EOF */
