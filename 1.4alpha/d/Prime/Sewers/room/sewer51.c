#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer41.c",
     "south" : M_ROOM+"sewer61.c",
     "east"  : M_ROOM+"sewer52.c",
     "west"  : M_ROOM+"sewer50.c",
    ]) );
}
