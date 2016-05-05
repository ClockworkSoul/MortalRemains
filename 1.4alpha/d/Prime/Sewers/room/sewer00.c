#include <mudlib.h>
#include <sewers.h>

inherit M_ROOM+"sewerstd.c";

void create() {
  ::create();
  set("exits", ([
		 "south" : M_ROOM+"sewer10.c",
		 "east": M_ROOM+"sewer01.c",
		 "up" : "/d/Prime/Central/room/road0_-4",
		 ]) );
  reset_quest();
}
