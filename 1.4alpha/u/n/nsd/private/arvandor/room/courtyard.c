/*
** File: courtyard.c
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
    set("short", "Courtyard of the tower");
    set( "long", @EndText
You're in the courtyard of the tower. The faeries reunite here
to have their harvester feasts, and sometimes they make their
rehearsals for the faerie rings. It's a wide chamber.
EndText
    );
    set( "exits", ([
      "south" : ARV_ROOM+"seelietower.c",
    ]) );
    set("item_desc", ([
    ]) );
}

/* EOF */
