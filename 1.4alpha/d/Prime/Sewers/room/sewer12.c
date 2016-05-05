#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer02.c",
     "south" : M_ROOM+"sewer22.c",
     "east"  : M_ROOM+"sewer13.c",
     "west"  : M_ROOM+"sewer11.c",
    ]) );
}
