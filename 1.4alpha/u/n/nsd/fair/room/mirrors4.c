/*
** File: mirrors4.c
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
Along the hallway of the House of Mirrors. There are
little chambers to east and west of this hall, in which
you'll find the mirrors. Check them out one by one, and
you'll have a lot of fun ;)
EndText);
    set( "exits", ([
      "west" : FAIR_ROOM+"mirrors5.c",
      "east" : FAIR_ROOM+"mirrors6.c",
      "north" : FAIR_ROOM+"mirrors7.c",
      "south" : FAIR_ROOM+"mirrors1.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
    ]) );
}

/* EOF */
