#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set("author","abyss");
    set( "light", 1 );
    set( "short", "Bayside Housing Co." );
    set( "long", @EndText
This is a room that will help you create your own little room.
Or rooms depends on if you want to pay for it.  It will let you keep
certain eq in this room for a certain ammount of time.  I will have 
this system up and running hopefully soon. So don't bug me saying it
doesnt work. cause I KNOW IT DOESNT!
Have a good day!
EndText
    );
    set( "exits", ([
   "hoss"  :  "/u/a/abyss/town/hoss.c",
     "east"  :  "/u/a/abyss/town/t2.c",
    ]) );
}
