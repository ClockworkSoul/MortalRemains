#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Bayside Avenue" );
    set( "long", @EndText
This is the center of Dragonstar.  To the north you notice some houses, to the
south you see some buildings and a park, to the east you see some shops , and 
to the west you see some more shops.  The road out of town is to the north or south.
EndText
    );
    set( "exits", ([
     "east"  :  "/u/a/abyss/town/center.c",
     "north"  :  "/u/a/abyss/town/pawn.c",
    ]) );
}
