#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
     "north" : M_ROOM+"sewer67.c",
     "west"  : M_ROOM+"sewer76.c",
    ]) );
}
