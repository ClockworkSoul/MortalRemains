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
Here, the road runs to the northeast and southwest. The
comforting sounds of the forest can still be heard, but
the woods begin to darken to the west. Tangles bushes
line either side of the road and shadows dance on the 
ground as light filters through the leaves high above
the road.
EndText
  );
  set( "item_desc", ([
    "road" : "This is the main road through the forest.\n",
    "forest" : "The forest begins to close in around the road, getting darker to the south.\n",
    "woods" : "The woods begin to close in around the road, getting darker to the south.\n",
    "bushes" : "Low bushes grow among the trees to either side of the road.\n",
    "trees" : "Tall trees lean over the road and spread thickly in all directions.\n",
    "shadows" : "Shadows dance on the road here. To the south, they get thicker and darker.\n",
    "leaves" : "Leaves blow in the wind, collect on the ground, and grow on the trees.\n",
    "ground" : "The ground beneath the trees is covered with bushes and dry leaves.\n"
  ]) ) ;
  set( "exits", ([
    "northeast" : "/u/r/rislyn/forest/road/road3.c",
    "southwest" : "/u/r/rislyn/forest/road/road5.c"
  ]) );
}



