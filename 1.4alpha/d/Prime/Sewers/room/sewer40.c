#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer30.c",
     "south" : M_ROOM+"sewer50.c",
     "east"  : M_ROOM+"sewer41.c",
    ]) );
}
