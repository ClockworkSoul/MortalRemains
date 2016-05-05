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
       "north" : AROOM+"street36.c",
       "south" : AROOM+"street35.c",
 ]) );
}
