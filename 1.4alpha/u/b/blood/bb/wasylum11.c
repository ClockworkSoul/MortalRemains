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
      "northwest-down" : BSMNT+"wasylum12.c",
      "north-up" : BSMNT+"wasylum10.c",
    ]) );
}
