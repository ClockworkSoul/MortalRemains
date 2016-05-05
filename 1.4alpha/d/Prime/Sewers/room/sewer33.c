#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer23.c",
     "south" : M_ROOM+"sewer43.c",
     "east"  : M_ROOM+"sewer34.c",
     "west"  : M_ROOM+"sewer32.c",
    ]) );
}
