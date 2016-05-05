#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;
int i;

void create(){
  ::create();
  set("light", 0);
  set("short", "A small shack");
  set("long", @Endtext
A smell of decaying meat drifts around this small shack.  The floor
creeks slightly as your weight rests on the old wooden floorboards.
Several spots on the floor are free of dust, indicating that some
furniture rested there not too long ago.  The windows have all been
boarded up, as if the former resident tried to keep something out.
Endtext
 );
  set("item_desc", ([
    "windows" : "They have been boarded up.\n",
    "floorboards" : "A few boards are newer than the rest of the floorboards.\n",
    "floor" : "It is dirty.  You notice a few strange floorboards.\n",
  ]) );
  set("exits", ([
    "east"  : ROOMS+"road00",
  ]) );
  create_door("east", "west", "A wooden door with a broken lock", "closed");
  i = 0;
}

void init() {
  add_action("board_break", "break");
}

int board_break(string str) {
  if(!str || str != "floorboards") return 0;
  if(i != 0) return 0;
  if(TP->query("stat/strength") < 15) {
    write("You stomp viciously on the floorboards but to no avail.\n");
    say(TPCN+ " stomps viciously on the floorboards to no avail.\n");
    return 1;
  }
  write("You stomp on the strange floorboards, creating a large hole.\n");
  say(TPCN+ " stomps on a few floorboards, creating a large hole.\n");
  set("exits/down", ROOMS+ "shack03a");
  i = 1;
  return 1;
}
