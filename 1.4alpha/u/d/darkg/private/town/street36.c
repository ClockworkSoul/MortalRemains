#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()

{
 ::create();
 seteuid(getuid());
  set("light", 1);
  set("short", "Wade");
  set("exits", ([
       "east" : AROOM+"tavern2.c",
       "north" : AROOM+"street30.c",
       "south" : AROOM+"street34.c",
 ]));
}
