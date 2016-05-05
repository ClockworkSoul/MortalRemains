#include <teleport.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set("objects" , ([
      "haven's call" : "/d/Prime/Magehouse/items/hcall.c"
    ]) );
    set("no_teleport", NO_IN_OR_OUT);
    reset();
    set( "short", "Heaven's Embrace" );
    set( "long", @EndText
Crystal walls, and large pipes make this room a perfect place
for music or other sound of great beauty to be played here. In
fact, that is one of the most important things about this room.
Great and powerful voices sing of glorious times, of great war,
sadness and happiness.  You can only wonder at the source of
the phantom voices or if they suggest other powers.
EndText
    );
}   
