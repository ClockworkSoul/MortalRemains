#include "basement.h"
#include <config.h>
#include <mudlib.h>
    
inherit ROOM;
    
void create()
{
    ::create();
    seteuid( getuid() );
    set("objects",([
    "gnome" : "/d/Prime/Magehouse/monsters/gnome2.c",
    ]) );
    reset();
    set( "light", 1 );
    set("author","blood");
    set( "short", "Guard Room" );
    set( "long", @EndText
This room is very spartain in nature, a table, weapons bench and chair
are the only things in here.  a guard sits here, watching all who walk
in, making sure that people aren't coming in with evil intentions.
EndText
    );

    set( "exits", ([
      "east" : BSMNT+"gcamp1.c",
    ]) );
}   
