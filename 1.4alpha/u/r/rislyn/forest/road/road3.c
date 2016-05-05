#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Bend in the road" );
  set( "long", @EndText
From this bend in the road, an opening in the forest to
the north is barely visible. To the southwest, the road
continues deeper into the woods. While the forest here
is not especially thick, brambles and tangled brush make
leaving the road impossible.
EndText
  );
  set( "item_desc", ([
    "bend" : "The road curves around here and continues in a different direction.\n",
    "road" : "This is the main road through the forest.\n",
    "forest" : "This is a large forest south of the city Stonekeep.\n",
    "opening" : "There is a small opening in the forest along the road to the north.\n",
    "woods" : "Tall trees blend together into darkness as the forest thickens.\n",
    "brambles" : "Brambles curl and climb in and around the brush.\n",
    "brush" : "Bushes, weeds, and vines tangle together across the ground.\n",
    "bushes" : "Low bushes grow among the trees to either side of the road.\n",
    "weeds" : "Weeds of all kinds grow out of control along either dies of the rod.\n",
    "vines" : "Green vines crawl across the ground and hang from trees.\n",
    "ground" : "The ground under the tres is covered with brush.\n"
  ]) ) ;
  set( "exits", ([
    "north" : "/u/r/rislyn/forest/road/road2.c",
    "southwest" : "/u/r/rislyn/forest/road/road4.c"
  ]) );
}



