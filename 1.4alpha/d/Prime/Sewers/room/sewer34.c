#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer24.c",
     "south" : M_ROOM+"sewer44.c",
     "east"  : M_ROOM+"sewer35.c",
     "west"  : M_ROOM+"sewer33.c",
    ]) );
}
