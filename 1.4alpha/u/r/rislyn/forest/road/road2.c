#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Forest road" );
  set( "long", @EndText
Several small trails lead away from the road here, but they
are quickly swallowed up by vines, weeds, and bushes. Birds
sing in the canopy high above the road while small animals
scamper through the brush. To the north can be seen an
opening in the forest. To the south, the road continues. The
forest rises impenitrably to the east and west.
EndText
  );
  set( "item_desc", ([
    "trails" : "Small, narrow trails made by animals lead off into the forest.\n",
    "road" : "This is the main road through the forest.\n",
    "vines" : "Green vines crawl across the road and hang from trees.\n",
    "trees" : "Tall trees stand on both sides of the road.\n",
    "ground" : "The ground here is dry and dotted with hardy grass.\n",
    "grass" : "Bright green grass springs up from the dirt in the center of the road.\n",
    "dirt" : "Dry brown dirt mixes with small rocks to cover the road.\n",
    "weeds" : "Weeds of all kinds grow out of cntrol at the edges of the road.\n",
    "bushes" : "Low bushes grow among the trees to either side of the road.\n",
    "birds" : "The chirps and whistles of birds fill the air, but no birds can be seen.\n",
    "canopy" : "Leafy tree branches form a green canopy high above the ground.\n",
    "branches" : "Tree branches sway back and forth as the wind blows.\n",
    "animals" : "Small animals scurry through the brush, making rustling noises.\n",
    "brush" : "Bushes, weeds, and vines tangle together across the forest floor.\n",
    "opening" : "There is an opening in the forest along the road to the north.\n",
    "forest" : "This is a large forest south of the city Stonekeep.\n"
  ]) ) ;
  set( "exits", ([
    "north" : "/u/r/rislyn/forest/road/road1.c",
    "south" : "/u/r/rislyn/forest/road/road3.c"
  ]) );
}



