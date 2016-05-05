/*
** File: /d/Planar/Abyss/Nazi/room/limbo2.c
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
    set( "short", "NAZI italian" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Italian troops ready to swear aligiance to Hitler all
around the room. You have no access to them, but you 
can see them. This was the last vision of Musolini.
You feel uncomfortable here...
EndText
    );
    set( "exits", ([
      "up" : NAZI_ROOM+"nazi3.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "musolini" : NAZI_MON+"Musolini.c",
    ]) );
    reset();
}
