#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "south" : M_ROOM+"sewer14.c",
     "east": M_ROOM+"sewer05.c",
     "west":M_ROOM+"sewer03.c",
    ]) );
}

