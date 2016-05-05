/*
** File: frthfloor5.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Inside the tower");
    set( "long", @EndText
You are in the hallway of the fourth floor. The passage continues
to northeast and northwest. Torches line the wall, high up in their
sconces.
EndText);
    set( "exits", ([
      "northwest" : ARV_ROOM+"frthfloor4.c",
      "northeast" : ARV_ROOM+"frthfloor6.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
