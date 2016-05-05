#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();

  set("exits", ([
     "south" : M_ROOM+"sewer13.c",
     "east": M_ROOM+"sewer04.c",
     "west":M_ROOM+"sewer02.c",
    ]) );
}

