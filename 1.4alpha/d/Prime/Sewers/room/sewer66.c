#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer56.c",
     "south" : M_ROOM+"sewer76.c",
     "east"  : M_ROOM+"sewer67.c",
     "west"  : M_ROOM+"sewer65.c",
    ]) );
}
