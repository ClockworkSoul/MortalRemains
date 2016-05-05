#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 1);
set ("area_type", ([
  "green" : 1,
  "black" : 2,
  ]) );
set ("short", "Cliff Base");
  set( "long", @EndText
You are at the base of a steep cliff. Directly above you is a wide ledge and
far above that some natural sunlight can be seen. To the northeast is a
steeply climbing path and the ground becomes sandy toward the south.
EndText
  );
  set( "exits", ([
"northeast" : MAIN+"/loop.c",
"south" : MAIN+"/ocean.c",
  ]) );

set ("item_desc", ([
  "sunlight" : "It is entering through a hole in the cavern ceiling.\n",
  "path" : "It probably leads to the top of the cliff.\n",
]) );
}
