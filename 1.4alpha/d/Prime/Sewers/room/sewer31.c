#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer21.c",
     "south" : M_ROOM+"sewer41.c",
     "east"  : M_ROOM+"sewer32.c",
     "west"  : M_ROOM+"sewer30.c",
    ]) );
}
