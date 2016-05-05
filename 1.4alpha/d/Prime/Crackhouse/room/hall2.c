#include <mudlib.h>
#include <where.h>

inherit ROOM;

void create() {
    ::create();
    set("author","cattt");
    set("light", 1);
    set("short", "End of a hallway");
    set("long", wrap(
	"The hallway ends here as the living room is north of here. "+
	"To the west you see what appears to be a small bedroom while a "+
	"staircase heads up and down."
      ) );
    set("item_desc", ([
      "hallway" : "Dark and creepy, this hallway needs to certainly be
cleaned up. \n",
  "living room" : "From over here, the room looks almost as bad as
here.\n",
  "bedroom" : "You cannot see it from here.\n",
  "stairs" : "The stairs don't look strong enough to hold anyone.\n",
  "staircase" : "The stairs don't look strong enough to hold anyone.\n",
                 ]) );
 set("exits", ([
    "up" : M_ROOM+"stairs.c",
    "down" : M_ROOM+"basement.c",
    "south" : M_ROOM+"hallway.c",
    "west" : M_ROOM+"bedroom1.c",
    "north" : M_ROOM+"lroom.c",
   ]) );
}
