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
set("short","Side of Cave");
  set( "long", @EndText
You are climbing along a path etched into the side of the cave wall.
Above you, there is only darkness with a flapping sound reverberating
off of the rocks. Below you is main part of the northern caves.
EndText
  );
set("exits",([
"down":INS_ROOM+"cave3.c",
"up":INS_ROOM+"cave5.c",
]));

}
