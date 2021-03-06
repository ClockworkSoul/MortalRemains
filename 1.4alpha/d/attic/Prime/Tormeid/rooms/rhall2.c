// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A hallway in the royal chambers.");
  set("long", @ENDLONG
You stand in an ornately decorated hallway in the royal chambers.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "north" : ROOMS(rhall1),
    "east" : ROOMS(rhall3),
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
