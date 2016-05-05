/*
** File: mirrors7.c
** Author: Lady Nsd
*/

#include <config.h>
#include <mudlib.h>
#include "fair.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Inside the House of Mirrors");
    set( "long",@EndText
End of the hallway of the House of Mirrors. There are
little chambers to east and west of this hall, in which
you'll find the mirrors. Check them out one by one, and
you'll have a lot of fun ;)
EndText);
    set( "exits", ([
      "west" : FAIR_ROOM+"mirrors8.c",
      "east" : FAIR_ROOM+"mirrors9.c",
      "south" : FAIR_ROOM+"mirrors4.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
    ]) );
}

/* EOF */
