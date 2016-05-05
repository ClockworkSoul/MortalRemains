#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer26.c",
     "south" : M_ROOM+"sewer46.c",
     "east"  : M_ROOM+"sewer37.c",
     "west"  : M_ROOM+"sewer35.c",
    ]) );
}
