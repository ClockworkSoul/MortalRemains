// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;
inherit DOORS ;

void create() {
  seteuid(getuid());
  set("short", "A hallway in the royal chambers.");
  set("long", @ENDLONG
You stand in an ornately decorated hallway.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
    "west" : ROOMS(bnhall6),
    "south" : ROOMS(rhall2),
  ]) );
  create_door("west", "east", 
  "A beautiful mahogany door.",
   "locked", "royal_key", 24) ;
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
