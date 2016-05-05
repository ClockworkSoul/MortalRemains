#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Open forest" );
  set( "long", @EndText
The trees here are far apart, making travel between
them easy, but there are no recognizable paths. Thick
brush blocks passage to the north while the beautiful
forest spreads out in every other direction. A
particularly large tree stands to the southeast and
bird song fills the air.
EndText
  );
  set( "item_desc", ([
    "trees" : "The trees here are tall, straight, and spread out.\n",
    "brush" : "Tangled brush grows beneath the trees to the north.\n",
    "forest" : "This is a beautiful, open forest which spread out in all directions.\n",
    "tree" : "A large, beautiful tree dominates the forest to the southeast.\n",
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/lforest/forest6.c",
    "west" : "/u/r/rislyn/forest/lforest/forest4.c",
    "south" : "/u/r/rislyn/forest/lforest/forest13.c"
  ]) );
}



