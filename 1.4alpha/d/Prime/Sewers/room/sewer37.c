#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer27.c",
     "south" : M_ROOM+"sewer47.c",
     "west"  : M_ROOM+"sewer36.c",
    ]) );
}
