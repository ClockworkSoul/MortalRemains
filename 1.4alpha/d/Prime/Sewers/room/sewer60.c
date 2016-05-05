#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer50.c",
     "south" : M_ROOM+"sewer70.c",
     "east"  : M_ROOM+"sewer61.c",
    ]) );
}
