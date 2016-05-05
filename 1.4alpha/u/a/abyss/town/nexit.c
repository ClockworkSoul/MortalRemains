#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Center of Town" );
    set( "long", @EndText
This is the center of Tantallon.  To the north you notice some houses, to the
south you see some buildings and a park, to the east you see some shops , and 
to the west you see some more shops.  The road out of town is to the north or south.
EndText
    );
    set( "exits", ([
      "start" : START,
     "south"  :  "/u/a/abyss/town/ta.c",
    ]) );
}
