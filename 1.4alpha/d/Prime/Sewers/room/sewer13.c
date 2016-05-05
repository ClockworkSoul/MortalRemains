#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer03.c",
     "south" : M_ROOM+"sewer23.c",
     "east"  : M_ROOM+"sewer14.c",
     "west"  : M_ROOM+"sewer12.c",
    ]) );
}
