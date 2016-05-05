#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "south" : M_ROOM+"sewer17.c",
     "west":M_ROOM+"sewer06.c",
    ]) );
}

