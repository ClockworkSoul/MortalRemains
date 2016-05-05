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
Leaves crunch softly on the moss covered ground.
The forest opens up here, with travel possible in
any direction. A tall, magestic tree draws
attention to the south while other trees, of all
kinds and sizes, grow all around.
EndText
  );
  set( "item_desc", ([
    "leaves" : "Fallen leaves of all colors collect on the ground.\n",
    "ground" : "Soft moss and fallen leaves carpet the ground of the forest.\n",
    "moss" : "Soft, inviting, dark green moss blankets the forest floor.\n",
    "forest" : "This is a pleasant, open forest. The sounds of forest life fill the air.\
n",
    "tree" : "A single tree, larger than any other is sight, stands in the forest to the
south.\n",
    "trees" : "Trees of many kinds spread out in all directions. They are far enough apar
t to travel between easily.\n",
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/lforest/forest7.c",
    "west" : "/u/r/rislyn/forest/lforest/forest5.c",
    "north" : "/u/r/rislyn/forest/lforest/forest1.c",
    "south" : "/u/r/rislyn/forest/lforest/forest14.c"
  ]) );
}
