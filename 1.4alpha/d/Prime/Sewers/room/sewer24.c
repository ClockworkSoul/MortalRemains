#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer14.c",
     "south" : M_ROOM+"sewer34.c",
     "east"  : M_ROOM+"sewer25.c",
     "west"  : M_ROOM+"sewer23.c",
    ]) );
}
