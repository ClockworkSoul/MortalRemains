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
EndText
    );
    set( "exits", ([
     "west"  :  "/u/a/abyss/town/center.c",
     "south"  :  "/u/a/abyss/town/guns.c",
    ]) );
}
