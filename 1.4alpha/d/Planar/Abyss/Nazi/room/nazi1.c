/*
** File: nazi1.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
** Special thanks: To my beloved Shya for teaching me the
**               ganging function on the nazi soldiers.
**               She rocks!!!
*/

#include <config.h>
#include <mudlib.h>
#include "nazi.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "NAZI Hell Layer" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
This is the part of hell in which all those evil leaders
of world war II rest for a long eternity. You don't feel
good here. Your nerves betray you...
EndText
    );
    set( "exits", ([
      "enter" : NAZI_ROOM+"nazi5.c",
    ]) );
    set("item_desc", ([
    ]) );
}
void init() {
    add_action("block_nazi", "kill") ;
    add_action("block_nazi", "steal" ) ;
    add_action("block_nazi", "backstab");
    add_action("block_nazi", "cast");
    add_action("block_nazi", "sneak");
}
int block_nazi (string str) {
    if (str == "nazi") {
	if (present("nazi", TO)) {
	    object *inventory;
	    int i;
	    inventory = all_inventory (TO);
	    for (i = 0; i < sizeof(inventory); i++)
		if (inventory[i]->id("nazi")) {
		    write ("The soldiers gang up on you!\n");
		    inventory[i]->kill_ob(TP);
		}   {
		return 1;
	    }
	}
    }
}
/* EOF */
