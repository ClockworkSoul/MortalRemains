#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
  ::create();
  seteuid( getuid() );
  set( "light", 1 );
  set("author","shallar");
set("short", "Narrow Passage");
  set( "long", @EndText
You are walking along a narrow passage in the underground caves. To
the east is the main cavern, where you started this journey. Off to
the west, the cave branches out to some ruins.
EndText
  );
set("exits",([
"east":INS_ROOM+"cave1.c",
"west":INS_ROOM+"cave15.c",
]));
}


