#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer07.c",
     "south" : M_ROOM+"sewer27.c",
     "west"  : M_ROOM+"sewer16.c",
    ]) );
}
