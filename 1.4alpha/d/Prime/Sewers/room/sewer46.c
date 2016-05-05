#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer36.c",
     "south" : M_ROOM+"sewer56.c",
     "east"  : M_ROOM+"sewer47.c",
     "west"  : M_ROOM+"sewer45.c",
    ]) );
}
