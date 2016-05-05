/*
** File: /d/Planar/Abyss/Nazi/room/nazi12.c
** Author: Lady Nsd, Mistress of Darkness (Mind Seductress)
*/

#include "nazi.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set( "short", "NAZI japanese" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Barely human forms screaming for help with
their flesh burned after LITTLE BOY and FAT MAN were dropped.
They're all around the room. You have no access to 
them, but you can see them. This was the last vision
of Hirohito. You feel uncomfortable here...
EndText
    );
    set( "exits", ([
"north" : NAZI_ROOM+"nazi11.c",
"east" : NAZI_ROOM+"nazi2.c",
    ]) );
    set("item_desc", ([
    ]) );
}

void reset() {
    object s1, s2;

    if (!present("soldier", this_object() )){
	s1 = clone_object( NAZI_MON+"soldiers.c" );
	s1->move(this_object());

	s2 = clone_object( NAZI_MON+"soldiers.c" );
	s2->move(this_object());

    }

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
/* EOF */
