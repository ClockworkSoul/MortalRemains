// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A simple bedroom.");
  set("long", @ENDLONG
This is the simple bedroom of a commoner in the castle.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
   "south" : ROOMS(agdhall4),
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
