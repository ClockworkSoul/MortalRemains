#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM;

void create()

{
 ::create();
seteuid(getuid());
  set("light", 1);
  set("short", "Sciv avenue");
  set ("exits", ([
       "west" : AROOM+"street32.c",
 ]) );
}
