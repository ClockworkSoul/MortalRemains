#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Forest path" );
  set( "long", @EndText
The forest to the south opens up greatly. Trees rise
above a moss and leaf covered ground. Light shines
down through the leaves of the canopy, creating a
beautiful effect of light and shadows. The main road
lies to the north and tangled brush blocks passage
east and west.
EndText
  );
  set( "item_desc", ([
    "forest" : "The forest here is open and comforting. The sounds of forest life can be heard everywhere.\n",
    "trees" : "Tall trees rise up all around the path. They spread father apart to the south.\n",
    "path" : "This is a narrow forest path connecting the main road in the north to the open forest in the south.\n",
    "moss" : "Soft, dark green moss covers the forest floor.\n",
    "ground" : "The ground here is covered with soft moss and fallen leaves.\n",
    "leaves" : "Fallen leaves carpet the ground around the path.\n",
    "canopy" : "The canopy thins ot here, allowing more light through.\n",
    "shadows" : "Soft shadows dance across the ground in mesmerizing patterns.\n",
    "patterns" : "Beautiful patterns of light and dark play across the ground/\n",
    "bushes" : "Thick bushes to either side of the path prevent travel to the east and west.\n"
  ]) );
  set( "exits", ([
    "north" : "/u/r/rislyn/forest/eastroad/road4.c",
    "south" : "/u/r/rislyn/forest/lforest/forest2.c"
  ]) );
}



