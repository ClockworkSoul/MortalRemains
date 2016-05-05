/*
** File: seeliecourt1.c
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
    set("short", "Pathway to Seelie Court");
    set( "long", @EndText
This is a small clearing. It reveals a path to another village. There
are no pine trees in this part of the forest, only thin fir trees.
It's strange how it makes you feel you're in a completely
different place. It makes no sense at all.
EndText );
    set( "exits", ([
      "west" : ARV_ROOM+"riverway3.c",
      "east" : ARV_ROOM+"seeliecourt2.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("listen", wrap(
	"You hear nothing. The excessive silence makes you worry...\n"));
}

/* EOF */
