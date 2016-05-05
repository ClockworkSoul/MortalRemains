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
  "black" : 1,
  "red" : 3,
  ]) );
set ("short", "Lava Tube");
  set( "long", @EndText
You are in a tight chimney of solidified lava. It extends up at least another
hundred feet and down to a large room far below. A large crack opens to
the south, probably the result of a shift in the rock strata.
EndText
  );
  set( "exits", ([
"south" : MAIN+"/barren.c",
"up" : MAIN+"/lava2.c",
  ]) );

set ("item_desc", ([
]) );
}
