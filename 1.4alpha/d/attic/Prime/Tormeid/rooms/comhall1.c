// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Commoner Mess Hall.");
  set("long", @ENDLONG
You are in the Commoner Mess Hall, where the commoners of the Castle
make and eat their own food, seperate from the royalty and guests.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(comhall2),
    "south" : ROOMS(comhall3),
   "east" : ROOMS(bshall4),
  ]) );
  set("item_desc", ([
  ]) );
  set("search_desc", ([
  ]) );
  set("objects", ([
   MON(commoner) : random(5)  + 3,
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
