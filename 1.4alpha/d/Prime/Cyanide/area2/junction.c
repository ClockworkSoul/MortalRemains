#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( 0 );
set ("author", " -{ CYANIDE }- ");
set ("light", 0);
set("short", "Junction");
  set( "long", @EndText
You are at the junction of a north-south passage and an east-west passage.
From the north, you distinctly feel a chill air. The way to the south
is relatively cramped, but a wider trail leads to the west. The tunnel to
the east has unfourtunately been collapsed, and is impassable.
EndText
  );
  set( "exits", ([
"north" : MAIN+"/cool.c",
"west" : MAIN+"/barren.c",
"south" : MAIN+"/creepy.c",
  ]) );

set ("item_desc", ([
]) );
}
