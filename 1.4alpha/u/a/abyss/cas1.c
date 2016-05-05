#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "The Throne Room" );
    set( "long", @EndText
This is a very comfortable looking room.  There is a throne on the south wall.
The throne looks to sit two people.  You wounder where the King and Queen are.
EndText
    );
    set( "exits", ([
     "north"  :  "/u/a/abyss/workroom.c",
]) );
}
