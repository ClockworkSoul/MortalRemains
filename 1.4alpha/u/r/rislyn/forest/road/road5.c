#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "Crossroads" );
  set( "long", @EndText
A faded wooden sign post stands to the south. The
road leads off in three directions here, and
the forest grows noticably darker to the
southwest. A trail goes off to the south, past
the sign post, but it is blocked after a few
steps by a massive wall of brambles.
EndText
  );
  set( "item_desc", ([
    "sign" : "An arrow-shaped piece of wood points northeast.\n",
    "wood" : "The word 'Stonekeep' is carved deeply into the wood.\n",
    "post" : "A wooden post is set solidly in the ground here. A sign is nailed to the post.\n",
    "ground" : "The ground here is dry and dusty. This intersection is aparently well-used.\n",
    "intersection" : "This is a three-way crossroads in the middle of the forest.\n",
    "forest" : "This is a pleasant forest, although it grows mush darker to the west.\n",
    "trail" : "A narrow trail made by some animal runs south from the crossroads.\n",
    "crossroads" : "This is a three-way crossroads in the middle of the forest.\n",
    "wall" : "Brambles rise to the south to form an imposing wall.\n",
    "brambles" : "Brambles rise out of the forest to the south.\n"
  ]) ) ;
  set( "exits", ([
    "northeast" : "/u/r/rislyn/forest/road/road4.c",
    "southeast" : "/u/r/rislyn/forest/eastroad/road1.c",
    "southwest" : "/u/r/rislyn/forest/westroad/road1.c"
  ]) );
}



