#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set( "short", "A feline's paradise" );
  set( "long", @EndText
This cozy hideaway has warm and friendly aura.  
Kittens scamper about playing with each other happily.
One extremely small one jumps on your lap and starts
purring and curls up in a ball to take a nap.
EndText
  );
  call_other("/u/c/cattt/obj/to_do_board", "board");
  set( "exits", ([
    "slums" : "/d/Prime/Crackhouse/room/entrance.c",
    "sewers": "/d/Prime/Sewers/sewers00.c",
    "den"   : "/u/c/cattt/room/newden.c",
    "start" : START,
    "void"  : VOID,
                     ]) );
  reset();
}
