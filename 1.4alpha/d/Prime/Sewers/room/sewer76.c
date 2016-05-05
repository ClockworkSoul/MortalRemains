#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer66.c",
     "east"  : M_ROOM+"sewer77.c",
     "west"  : M_ROOM+"sewer75.c",
    ]) );
}
