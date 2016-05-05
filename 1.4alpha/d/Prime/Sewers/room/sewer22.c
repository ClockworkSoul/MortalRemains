#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer12.c",
     "south" : M_ROOM+"sewer32.c",
     "east"  : M_ROOM+"sewer23.c",
     "west"  : M_ROOM+"sewer21.c",
    ]) );
}
