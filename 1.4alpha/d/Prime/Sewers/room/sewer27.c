#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer17.c",
     "south" : M_ROOM+"sewer37.c",
     "west"  : M_ROOM+"sewer26.c",
    ]) );
}
