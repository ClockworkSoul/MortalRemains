#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("light", 0);
set ("arena", 1);
set ("area_type", ([
  "black" : 2,
  ]) );
  set ("short", "Barren Area");
  set( "long", @EndText
You are west of the junction, where the rock-bound passage widens out
into a large, flat area. Athough the land here is barren, you can see
vegetation to the west. South of here is a mighty wall of stone, ancient
and crunbling. To the southwest the wall has decayed enough to form an
opening, through which seeps a thin mist. A trail dips sharply into rocky
terrain to the northwest.
EndText
  );
  set( "exits", ([
"north" : MAIN+"/lava.c",
"northwest" : MAIN+"/loop.c",
"west" : MAIN+"/cliff.c",
"southwest" : MAIN+"/LOS02.c",
"east" : MAIN+"/junction.c",
  ]) );

set ("item_desc", ([
  "mist" : "You cannot comprehend the meaning of the mist\n",
  "vegetation" : "An odd sight indeed down here.\n",
  "wall" : "Any decoration it once had has long since eroded away.\n",
]) );
}
