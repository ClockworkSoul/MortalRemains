#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Northern Bayside Road" );
    set( "long", @EndText
EndText
    );
    set( "exits", ([
     "north"  :  "/u/a/abyss/town/t3.c",
     "south"  :  "/u/a/abyss/town/center.c",
    ]) );
}
