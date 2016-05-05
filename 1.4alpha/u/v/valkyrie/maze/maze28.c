#include "maze.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;
inherit DOORS;

void create()
{   
    
    ::create();

    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
set("objects",(["gem" : "/d/Prime/Magehouse/items/ruby.c",                     
                "gem" : "/d/Prime/Magehouse/items/emerald.c",
                "gem" : "/d/Prime/Magehouse/items/sapphire.c",
]) );
    set( "short", "Room of Flames");
    set( "long", @EndText
The extreme heat that clings around your form as you walk in is opressive, huge
towers of flame shoot from the ceiling and walls coming dangerously close for
comfort. Your shadow seems to bounce about with the flames, and beautiful
treasures which are here for the taking.
EndText
    );

    set( "exits", ([
      "north" : MAZE+"maze22.c"
    ]) );
create_door("north", "south", "tall jets of heat surround this door, begging "+
"you to touch them, feeding there flames.", "locked", "flame key", 25);

}
