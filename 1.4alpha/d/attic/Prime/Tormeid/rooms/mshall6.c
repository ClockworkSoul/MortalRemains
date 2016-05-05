// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large hallway.");
  set("long", @ENDLONG
This large hallway runs north and south through the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(mshall5),
  "south" : ROOMS(s_stairs-1),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
