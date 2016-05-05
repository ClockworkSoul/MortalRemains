#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Forest edge" );
  set( "long", @EndText
This is the edge of a large forest. Trees loom tall all
around a dirt road which is wide enough for two wagons
to pass, although right now it is deserted. The only
sounds here are from birds and other forest creatures.
To the north, the city of Stonekeep opens up while the
road continues south into the forest. Dense vegitation
prevents passage in any other direction.
EndText
  );
  set ("item_desc", ([
    "forest" : "This is a large forest south of the city Stonekeep.\n",
    "trees" : "Tall trees stand on both sides of the road.\n",
    "road" : "This is the main road through the forest.\n",
    "dirt" : "Dry brown dirt mixed with small rocks covers the road.\n",
    "rocks" : "Small rocks combine with dirt to cover the road.\n",
    "birds" : "The chirps and whistles of birds fill the air, but no birds can be seen.\n",
    "creatures" : "The creatures of the forest conceal themselves well in the vegitation.\n",
    "vegitation" : "Dense tangled vegitation grows wildly at the edges of the road.\n"
  ]) ) ;
  set( "exits", ([
    "north" : "/u/m/maverick/mt/shadow8.c",
    "south" : "/u/r/rislyn/forest/road/road2.c",
  ]) );
}
 



