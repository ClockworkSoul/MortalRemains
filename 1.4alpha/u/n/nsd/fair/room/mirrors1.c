/*
** File: mirrors1.c
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
You're in the hallway of the House of Mirrors. There are
little chambers to east and west of this hall, in which
you'll find the mirrors. Check them out one by one, and
you'll have a lot of fun ;)
EndText);
    set( "exits", ([
      "west" : FAIR_ROOM+"mirrors2.c",
      "east" : FAIR_ROOM+"mirrors3.c",
      "north" : FAIR_ROOM+"mirrors4.c",
      "out" : FAIR_ROOM+"premirror.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
    ]) );
}

/* EOF */
