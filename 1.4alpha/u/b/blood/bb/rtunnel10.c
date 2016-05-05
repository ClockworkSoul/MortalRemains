#include "basement.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set("objects",([
    "rat" : "/d/Prime/Magehouse/monsters/rat1.c",
    "rat" : "/d/Prime/Magehouse/monsters/rat1.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author","blood");
    set( "short", "In the Rat Tunnels" );
    set( "long", @EndText
These grubby rodents have dug a series of tunnels, which you will have to
crawl through to proceed.
EndText
    );

    set( "exits", ([
      "north" : BSMNT+"rtunnel9.c",
      "west" : BSMNT+"rtunnel11.c"
    ]) );
}
