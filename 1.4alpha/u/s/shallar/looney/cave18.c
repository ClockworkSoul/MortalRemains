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
set("short","Wheel of Morality");
  set( "long", @EndText
This room is located at the bottom of the cave. There is a large wheel
with writing on it located at the center of the room and there is  a
magical printer attached to it. It looks like you can spin the wheel
and it will perform feats of unpredictable magic.
EndText
  );
set("exits", ([
"up":"/u/s/shallar/looney/cave1.c",
]));
}



