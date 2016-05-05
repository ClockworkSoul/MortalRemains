#include "newbie.h"
#include <config.h>
#include <mudlib.h>
#include <move.h>

inherit ROOM;
inherit DOORS;

int purse, open;

void create()
{   
    ::create();
    seteuid( getuid() );

    purse = 1;
    open = 0;

    set( "light", 1 );
    set("author","blood");
    set("objects",(["mage" : "/d/Prime/Magehouse/monsters/mage7.c"]) );
    reset();
    set( "short", "Bedroom" );
    set( "long", @EndText
This room strikes you as a sleeping place fit for a king.  A large soft
carpet covers the floor and master craftsmen have designed the bed, which is
off to the side of the room.  A chest of drawers sits on the other side of
the room along with a huge mirror that covers the other walls and the
ceiling.
EndText
    );

    set("item_desc", ([
      "chest" : "@@query_chest",
      "drawers" : "@@query_drawer",
      "drawer" : "@@query_drawer",
    ]) );
    set( "exits", ([
      "northeast" : N_ROOM+"room4.c",
    ]) );

    create_door("northeast","southwest", "A mahogany door inlayed  with silver "+
      "script that glows with the hints of magical protection.", "locked", 
      "cheese key", 25);

}   

void init() {
    add_action("open_func", "open");
    add_action("close_func", "close");
    add_action("get_func", "get");
    add_action("get_func", "take");
}

int get_func(string str) {
    string what, from;
    int flag;

    if (!str || !open) return 0;

    if (str!="purse" && str!="coin purse") {
	if (sscanf(str, "%s from %s", what, from)!=2) 
	    return 0;
    } else {
	what = "purse"; from = "drawers";
    }

    if ((what=="purse" || what=="coin purse") &&
      (from=="drawer" || from=="drawers")) {

	if (purse) {
	    object p = clone_object(BASE_PATH+"purse.c");
	    object coins = clone_object("/std/coins.c");

	    if (!p) {
		write("Error loading purse object!\n"+
		  "Notify Blood or Cyanide immediately!\n");

		destruct(coins);
		return 1;
	    }


	    if (p->move(TP) == MOVE_OK) {    
		write("You take a coin purse.\n");
		coins->set_number(1000);
		coins->move(p);
		say(TPN+" takes something from the drawer.\n");
		purse = 0;
	    } else {
		write("You cannot take that.\n");
		destruct(purse);
	    }
	    return 1;
	}
    }

    return 0;
}

int close_func(string str) {
    if (str=="drawer" || str=="drawers") {
	if (!open) {
	    write("It's already closed!\n");
	    return 1;
	}

	write("You close the drawers.\n");
	say(TPN+" closes the drawers.\n");
	open = 0;

	return 1;
    }
    return 0;
}

int open_func(string str) {
    if (str=="drawer" || str=="drawers") {
	if (open) {
	    write("It's already open!\n");
	    return 1;
	}

	write("You open one of the drawers.\n");
	say(TPN+" opens one of the drawers.\n");
	open = 1;

	return 1;
    }
    return 0;
}

string query_drawer() {
    string str;

    if (open) {
	str = "The chest has one drawer wide open. ";
	if (purse)
	    str += "Inside, is a large coin purse.";
	else
	    str += "It appears to be empty.";
    } else {
	str = "All the drawers are currently closed.";
    }

    return wrap(str);
}

string query_chest() {
    string str;

    str = "A solid oak chest with many drawers for storing "+
    "clothes and other private items. ";

    if (open)
	str += "One of its drawers is wide open.";
    else
	str += "All of its drawers are closed.";

    return wrap(str);
}

/* EOF */
