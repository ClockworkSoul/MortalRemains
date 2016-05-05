#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "south" : M_ROOM+"sewer11.c",
     "east": M_ROOM+"sewer02.c",
     "west": M_ROOM+"sewer00.c",
    ]) );
}
