#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer04.c",
     "south" : M_ROOM+"sewer24.c",
     "east"  : M_ROOM+"sewer15.c",
     "west"  : M_ROOM+"sewer13.c",
    ]) );
}
