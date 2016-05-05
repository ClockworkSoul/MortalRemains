/*
** File: /d/Planar/Abyss/Nazi/room/limbo4.c
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
    set( "short", "NAZI German" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Rotten corpses of Jews all around the room. You have no
access to them, but you can see them. This was the last
vision of Hitler. You feel uncomfortable here...
EndText
    );
    set( "exits", ([
      "up" : NAZI_ROOM+"nazi14.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "hitler" : NAZI_MON+"Hitler.c",
    ]) );
    reset();
}
