#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Well traveled road" );
  set( "long", @EndText
A vine hangs down from the canopy here. It dangles,
swaying slightly, at the side of the road. Higher
up, more vines can be seen hanging from branches.
The road runs east and west from here. Trails
through the brush begin to the north and south, but
only the smallest animals could follow them.
EndText
  );
  set( "item_desc", ([
    "vine" : "A dull green vine hangs down from the canopy above. It reaches to several feet above the ground.\n",
    "canopy" : "Tree branches reach over the road to form a bright green canopy.\n",
    "ground" : "The ground here is dry and hard-packed, perfect for traveling.\n",
    "branches" : "Tree brances reach out over the road, swaying gently in the breeze.\n",
    "road" : "The road here is wide and looks well traveled.\n",
    "vines" : "Vines of different shades of green hand down from the canopy high above the road.\n",
    "trails" : "Small trails made by animals lead off from the road and are quickly swalloed up by the brush.\n",
    "brush" : "Thick brush blocks travel to the north and south.\n"
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/eastroad/road3.c",
    "west" : "/u/r/rislyn/forest/eastroad/road1.c"
  ]) );
}



