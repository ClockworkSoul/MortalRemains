#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  set( "short", "Well traveled road" );
  set( "light", 1 );
  set( "short", "A workroom" );
  set( "long", @EndText
The road here looks well traveled. It is wide,
closed in to the north and south by large bushes.
Trees climb up from the brush, reaching high into
the air. Light filters through their leaves and
plays changing patterns across the ground. To the
northwest the road forks off in two directions.
EndText
  );
  set( "item_desc", ([
    "road" : "This wide dirt road looks well traveled.\n",
    "dirt" : "Dry dirt covers the surface of the road.\n",
    "surface" : "The surface of the road is even from frequent travel.\n",
    "bushes" : "Large bushes cluster beneath the trees on either side of the road.\n",
    "trees" : "Tall trees rise up out of the bushes all around the road.\n",
    "brush" : "Dense tangles of vines and bushes grow beneath the tall trees.\n",
    "vines" : "Dark green vines curl in and around trees and bushes.\n",
    "leaves" : "Leaves of all colors sway high above the road.\n",
    "patterns" : "Changing patterns of light and darks dance across the road as the leaves above blow in the wind.\n",
    "ground" : "The ground here is dry dirt, good for traveling on.\n",
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/eastroad/road2.c",
    "northwest" : "/u/r/rislyn/forest/road/road5.c"
  ]) );
}




