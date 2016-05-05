#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer65.c",
     "east"  : M_ROOM+"sewer76.c",
     "west"  : M_ROOM+"sewer74.c",
    ]) );
}
