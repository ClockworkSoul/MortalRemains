/*
** File: /u/n/nsd/library/cyberparty/sewerend.c
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
    set( "short", "End of rotten sewer" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long",@EndText
The sewer ends here. If you go outside, you'll
find yourself in a familiar place. Be glad you
found your way out safely.
EndText
    );
    set( "exits", ([
      "east" : POOL+"sewer5.c",
      "out" : "/d/Prime/Central/room/startroom.c",
    ]) );
    set( "item_desc", ([
      "walls" : "Neglected walls...\n",
      "sewer" : "Sigh... Just look around, dumb ass!!!!\n",
      "city" : "Not from here. You gotta find your way out first.\n",
    ]) );

    set("objects", ([
    ]) );
    reset();
}

/* EOF */
