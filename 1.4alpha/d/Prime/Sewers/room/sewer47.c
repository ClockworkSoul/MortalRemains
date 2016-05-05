#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer37.c",
     "south" : M_ROOM+"sewer57.c",
     "west"  : M_ROOM+"sewer46.c",
    ]) );
}
