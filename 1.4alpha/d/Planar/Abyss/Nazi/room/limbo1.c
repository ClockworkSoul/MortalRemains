/*
** File: /d/Planar/Abyss/Nazi/room/limbo1.c
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
    set( "short", "NAZI japanese" );
    // NB: "@EndText" should not have spaces after it.
    // "EndText" should be on a line of its own (no indentation, tabs or spaces)
    set( "long", @EndText
Barely human forms screaming for help with
their flesh burned after LITTLE BOY and FAT MAN were dropped.
They're all around the room. You have no access to 
them, but you can see them. This was the last vision
of Hirohito. You feel uncomfortable here...
EndText
    );
    set( "exits", ([
      "up" : NAZI_ROOM+"nazi5.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("objects", ([
      "hirohito" : NAZI_MON+"Hirohito.c",
    ]) );
    reset();
}
