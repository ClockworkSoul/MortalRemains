/*
** File: /d/Planar/Abyss/Nazi/room/nazi3.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
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
    set( "short", "NAZI italian" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Italian troops ready to swear allegience to Hitler all
around the room. You have no access to them, but you 
can see them. This was the last vision of Musolini.
You feel uncomfortable here...
EndText
    );
    set( "exits", ([
      "south" : NAZI_ROOM+"nazi5.c",
      "west" : NAZI_ROOM+"nazi6.c",
      "north" : NAZI_ROOM+"nazi13.c",
      "east" : NAZI_ROOM+"nazi17.c",
      "down" : NAZI_ROOM+"limbo2.c",
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
