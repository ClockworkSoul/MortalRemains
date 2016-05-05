#include <mudlib.h>
#include <path.h>

inherit ROOM;
void create(){
  ::create();
  set( "light", 0 );
  set( "short", "Dark alley" );
  set( "long", @EndText
Piles of garbage is stack against the walls in this alley.  A slimy
liquid is dripping down the eroded walls.  The decaying garbage that
has been left here emits a very offensive odor.
EndText
 );
  set( "item_desc", ([
    "walls" : "A lot of the slimy stuff is slowly oozing down the walls.\n",
    "garbage" : "Hordes of maggots are squirming around the trash.\n",
    "liquid" : "The foul chemical seem to be eating away the walls.\n",
  ]) );
  set( "exits", ([
    "east"  : ROOMS+"alley3.c",
    "west"  : ROOMS+"alley1.c",
  ]) );
}
