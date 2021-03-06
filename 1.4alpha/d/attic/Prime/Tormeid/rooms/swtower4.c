// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit STD(wg_room);

void create() {
  seteuid(getuid());
  set("short", "In the southwest tower, 4th floor.");
  set("long", @ENDLONG
You stand on the fourth floor of the southwest tower.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "up" : ROOMS(swtower5),
    "down" : ROOMS(swtower3),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
  ]) );
  set("exit_msg", ([
    "down" : "$N goes down the stairs.",
    "up" : "$N goes up the stairs.",
  ]) );
  ::create();
}
