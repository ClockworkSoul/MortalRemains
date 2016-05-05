#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "A bend in the road" );
  set( "long", @EndText
A large ditch marks the southern edge of the road
here. The road swings northeast around it while to
the west it runs straight. Ground vines threaten to
overrun the northern edge of the road, but frequent
travel has kept them back.
EndText
  );
  set( "item_desc", ([
    "ditch" : "A ditch, several feet deep, curves along the southern edge of the road.\n",
    "road" : "The road narrows slightly here as it curves north around a ditch.\n",
    "vines" : "Dull green vines with little yellow flowers crawl across the ground and spill onto the northern edge of the road.\n",
    "flowers" : "Small, bright yellow flowers grow on the vines to the north of the road.\n",
    "ground" : "The dry ground of the road is covered at the edges with crawling vines.\n"
  ]) );
  set( "exits", ([
    "northeast" : "/u/r/rislyn/forest/eastroad/road4.c",
    "west" : "/u/r/rislyn/forest/eastroad/road2.c"
  ]) );
}



