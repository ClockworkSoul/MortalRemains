#include <mudlib.h>
#include <path.h>

inherit ROOM;
inherit DOORS;
int x;
void create(){
  ::create();
  seteuid(getuid());
  set("light", 0);
  set("short", "A run-down shack");
  set("long", @Endtext
Obviously, there is no electricity running to this place anymore.
The windows are also boarded up since all the glass were shattered
some time ago.  A slight draft still drifts in, but it is warm
enough inside to be comfortable.  There are a few discarded cans
on the floor and a thin mattress in one corner of the room.
Endtext
 );
  set("item_desc", ([
    "windows" : "They are shattered and boarded up.\n",
    "glass" : "There is nothing but shards of glass by the window.\n",
    "cans" : "Some letters are scratched off, but you see 'C_mpb_ll's Soup'.\n",
    "mattress" :
      "Several springs are popping out of it.  It probably isn't too soft.\n",
  ]) );
  set("exits", ([
    "east" : ROOMS+ "house02",
    "west"  : ROOMS+"road00",
  ]) );
  create_door("west", "east", "A beat up wooden door", "closed");
  x = 0;
  reset();
}

void init() {
  add_action("get_glass", "get");
}

int get_glass(string str) {
  object ob1;

  if(str != "glass" && str != "shard") return 0;
  if(x != 0) {
    write("The pieces are all too small for any good use.\n");
    say(TPCN+ " searches through the glass pile by the window.\n");
    return 1;
  }
  ob1 = clone_object(OBJS+"glass");
  ob1->move(this_player());
  write("You get a sharp piece of glass by the window.\n");
  say(TPCN+ " gets a sharp piece of glass by the window.\n");
  x = 1;
  return 1;
}
