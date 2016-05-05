#include "basement.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set("objects",([
    "worm" : "/d/Prime/Magehouse/monsters/worm1.c",
    "worm" : "/d/Prime/Magehouse/monsters/worm1.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author","blood");
    set( "short", "Worm Asylum" );
    set( "long", @EndText
Twisty little passages and loops of tunnels lay before you. You imagine
that this is going to take a while to get through.
EndText
    );

    set( "exits", ([
      "north-down" : BSMNT+"wasylum3.c",
      "south-up" : BSMNT+"wasylum1.c",
    ]) );
}
