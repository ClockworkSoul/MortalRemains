#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", "cyanide");
set ("arena" ,1);
set ("light", 0);
set ("area_type", ([
  "blue" : 2,
  "black" : 2,
  ]) );
set ("short", "Ice Room");
  set( "long", @EndText
This is a large hall of ancient lava, since worn smooth by the movement of
a glacier. A large passageway exits to the east and an upward passage is at
the top of a jumble of fallen rocks.
EndText
  );
  set( "exits", ([
"up" : MAIN+"/lava.c",
"east" : MAIN+"/cool.c",
  ]) );

set ("item_desc", ([
]) );
}
