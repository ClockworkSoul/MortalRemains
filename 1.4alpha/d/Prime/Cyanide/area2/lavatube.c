#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("arena" ,1);
set ("light", 0);
set ("area_type", ([
  "red" : 2,
  "black" : 2,
  ]) );
  set ("short", "Lava Tube");
  set( "long", @EndText
You are in a dark and quite creepy crawlway with passages leaving to the
EndText
  );
  set( "exits", ([
"down" : MAIN+"/ice.c",
"south" : MAIN+"/barren.c",
  ]) );

set ("item_desc", ([
]) );
}
