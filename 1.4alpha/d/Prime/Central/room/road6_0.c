// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include "central.h"

void create() {
    ::create();
    set("author", "cyanide");
    set("light", 1);
    set ("short", RD_X);
    set("long", wrap(
	"Do something here."
      ) );
    set("exits", ([
      "east" : M_ROOM+"road6_0.c",
      "west" : M_ROOM+"road5_0.c"
    ]) );
    set("pre_exit_func", ([
      "east" : "bridge"
    ]) );
    set("item_desc", ([
    ]) );
}

int bridge() {
    if (!adminp(TP)) {
	write("Access to the bridge is blocked by a 20-foot high fence, "+
	  "\ntopped with miles of looped razor wire. You cannot cross.\n");
	return 1;
    }

    return 0;
}
// EOF
