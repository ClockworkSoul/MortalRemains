#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer40.c",
     "south" : M_ROOM+"sewer60.c",
     "east"  : M_ROOM+"sewer51.c",
    ]) );
}
