#include <config.h>
#include <mudlib.h>
 
inherit ROOM;
 
void create()
{
  ::create();
  seteuid( 0 );
  set( "light", 1 );
  set( "short", "A bend in the road" );
  set( "long", @EndText
The road continues to the east for a distance, until
it is swallowed by trees. It also winds off to the
southwest. The undergrowth to the north is tangled
and impassible, but a path leads off to the south.
The path looks like it was made by some animal, but
it is clear enough to follow.
EndText
  );
  set( "item_desc", ([
    "road" : "This is a wide, well traveled road through the forest.\n",
    "forest" : "The forest is pleasant here. Trees of all kinds surround the road.\n",
    "trees" : "Tall trees spread out in all directions. They are far enough apart to let light through so the forest does not appear imposing.\n",
    "undergrowth" : "Tangled undergrowth speads out along the sides of the road.\n",
    "path" : "This is a narrow path. Although small, it appears open enough to travel along.\n"
  ]) );
  set( "exits", ([
    "east" : "/u/r/rislyn/forest/eastroad/road5.c",
    "south" : "/u/r/rislyn/forest/lforest/forest1.c",
    "southwest" : "/u/r/rislyn/forest/eastroad/road3.c"
  ]) );
}



