#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "south" : M_ROOM+"sewer15.c",
     "east": M_ROOM+"sewer06.c",
     "west":M_ROOM+"sewer04.c",
    ]) );
}

