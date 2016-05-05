#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

int key_here;

void create()
{   
    ::create();
    seteuid( getuid() );
    key_here = 1;
    set( "light", 1 );
    set("author","blood");
    set( "short", "Cooking Area" );
    set( "long", @EndText
You have entered the cooking area of the mage's house.  A fire pit takes
up most of the center of the room though you can tell from the piles of
ashes in it that it hasn't been used for a while.  Tongs and other
utensils for cooking on a fire are also here.  Hooks, and poles hang from
the ceiling meant for smoking meats or fish.
EndText
    );
    set("item_desc",([
      "ashes" : "A pile of loose ashes in the fire pit.\n",
      "poles" : "These were used to smoke various meats and the like.\n",
      "hooks" : "These were used to smoke various meats and the like.\n",
      "firepit" : "A round pit used for cooking, it is full of ashes.\n",
    ]) );

    set( "exits", ([
      "southeast" : N_ROOM+"room13.c",
      "north" : N_ROOM+"room11.c"
    ]) );
}

void init() {
    add_action("search", "search");
}

int search(string str) {
    object key;

    if (str=="ashes") {
	if (key_here) {
	    key = clone_object(BASE_PATH+"cheesy_key.c");
	    key->move(TP);
	    write("You find a strange key in the ashes, and take it!\n");
	    say(TPN+" digs through the ashes.\n");
	    key_here = 0;
	    return 1;
	}
	return 0;
    }
}


/* EOF */
