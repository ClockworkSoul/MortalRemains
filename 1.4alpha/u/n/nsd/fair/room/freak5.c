/*
** File: freak5.c
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
    set( "short", "In the freak show...");
    set( "long",@EndText
This is one of the many rooms inside the canvas tent of
the freak show. You're about to witness how awful science
can be at times. Not everything is technology and outer
space, there are science mistakes too. You gotta have
an iron will and a strong stomach to be here.
EndText);
    set( "exits", ([
      "west" : FAIR_ROOM+"freak6.c",
      "east" : FAIR_ROOM+"freak4.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "cow" : FAIR_MON+"mistake.c",
    ]) );
    reset();
}
/* EOF */
