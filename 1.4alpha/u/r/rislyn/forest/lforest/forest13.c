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
them easy, but there are no recognizable paths.
The forest spreads out in all directions from here.
The ground is covered by a soft dark green moss while
a different moss, a golden yellow kind, clings to the
bases of the trees. To the east, a particularly large
tree stands out from the rest.
EndText
  );
  set( "item_desc", ([
    "trees" : "Tall trees grow all around as the forest continues in all directions.\n",
    "ground" : "The ground here is moist, covered by moss and fallen leaves.\n",
    "moss" : "Which kind of moss do you want to look at?\n",
    "green moss" : "Thick, soft, dark green moss carpets the forest floor.\n",
    "yellow moss" : "Golden yellow moss climbs up the tree trunks throughout the forest.\n",
    "trunks" : "The trunks of many of these trees are covered with yellow moss.\n",
    "tree" : "A large, beautiful tree stands out from the rest to the east.\n"
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/lforest/forest14.c",
    "west" : "/u/r/rislyn/forest/lforest/forest12.c",
    "north" : "/u/r/rislyn/forest/lforest/forest5.c",
    "south" : "/u/r/rislyn/forest/lforest/forest23.c"
  ]) );
}



