/*
** File: /d/Planar/Abyss/Nazi/room/limbo3.c
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
    set( "short", "NAZI spanish" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Spanish troops ready to attack all around the room.
All of them worshipping Hitler. You have no access
to them, but you can see them. This was the last
vision of Franco. You feel uncomfortable here...
EndText
    );
    set( "exits", ([
      "up" : NAZI_ROOM+"nazi13.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "franco" : NAZI_MON+"Franco.c",
    ]) );
    reset();
}
