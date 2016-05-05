#include <mudlib.h>
#include <path.h>

inherit ROOM;
void create(){
  ::create();
  set( "light", 0 );
  set( "short", "Dead end in alley" );
  set( "long", @EndText
You have reached a point in the alley where it appears you can go
no further due to a high stone wall.  Huge piles of garbage cover 
every inch of ground here.  The horrible reek of it makes you dizzy.
EndText
 );
  set( "item_desc", ([
    "wall" : "It is a really high brick wall.\n",
    "garbage" : "The garbage piles are incredibly nasty and smelly.\n",
  ]) );
  set( "exits", ([
    "west"  : ROOMS+"alley2.c",
  ]) );
}
