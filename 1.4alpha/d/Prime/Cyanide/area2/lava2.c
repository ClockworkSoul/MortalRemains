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
  "red" : 4,
  ]) );
set ("short", "Top of a Lava Tube");
  set( "long", @EndText
You are at the very top of a naturally formed chimney of solidified lava.
The chute opens up to a ledge of sorts to the north. A sulferous
wind blows here, creating an eerie howling sound as it crosses the mouth of
the lava tube.
EndText
  );
  set( "exits", ([
"down" : MAIN+"/lava.c",
"north" : MAIN+"/volview.c",
  ]) );

set ("item_desc", ([
]) );
}
