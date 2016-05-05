
inherit "inherit/room";
#include "/players/zanzibar/include/area.h"

void reset (status arg) {
  ::reset(arg);
  if(!arg) {
    set_short("A long hallway");
    set_long (
" You have come upon a long hallway lined with torches to see by. There are\n"+
" no distinct features as it looks that this hallway was cut from the earth\n"+
" itself.\n");
    set_items(({
        "hallway#long hallway","This hallway is long.",
        "torch#torches","There are half a dozen or so torches lining the walls h
ere.",
        "features#distinct features","There is really nothing to see here.",
        "earth","The earth you walk on.",
        "walls#wall","Basicly earthen with an occasional rock jutting out.",
"rock","Just your basic rock, like what you would find underground.",
    }));
    set_exits(({
        PATH+"room10.c","north",
        PATH+"room13.c","south",
    }));
  }
}
