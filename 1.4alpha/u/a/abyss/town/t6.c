#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Southern Bayside Road" );
    set( "long", @EndText
EndText
    );
    set( "exits", ([
     "north"  :  "/u/a/abyss/town/t5.c",
     "south"  :  "/u/a/abyss/town/t7.c",
    ]) );
}
