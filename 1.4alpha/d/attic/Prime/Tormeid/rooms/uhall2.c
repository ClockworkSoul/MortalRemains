// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
You stand in a hallway in the second floor of the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "east" : ROOMS(uhall3),
  "west" : ROOMS(uhall1),
  "south" : ROOMS(bedroom1),
  "north" : ROOMS(bedroom2),
  ]) );
  set("item_desc", ([
  ]) );
  set("objects", ([
 ]) );
  ::create();
}
