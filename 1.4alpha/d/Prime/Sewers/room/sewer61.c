#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer51.c",
     "south" : M_ROOM+"sewer71.c",
     "east"  : M_ROOM+"sewer62.c",
     "west"  : M_ROOM+"sewer60.c",
    ]) );
}
