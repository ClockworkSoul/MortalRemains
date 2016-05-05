// A room in the starting area, as yet unnamed.
// Blame goes to Cyanide, 22 May 1999

inherit ROOM;

#include <config.h>
#include "central.h"

void create() {
    seteuid(getuid());

    set("author", "cyanide");
    set("safe", 1);
    set("light", 1);
    set("short", "The YMAA");
    set("long", wrap(
	"You are inside the YMAA, the major community center of "+
	CITY_NAME+". The beige walls are covered by hundreds of "+
	"random posters and fliers, and the flourescent lighting "+
	"buzzes incessantly. There is a large board on the wall "+
	"here for anybody to post their random musings." +
	" There is a door to the south marked 'Staff Only'."
      ) );
    set("exits", ([
      "south" : WIZHALL,
      "east" : M_ROOM+"road0_0.c",
    ]) );
    set("listen", "All you hear is those damn fluorescent lights!\n");
    set("item_desc", ([
      "walls" : "They are beige, and covered with posters.\n",
      "posters" : "Various posters suggesting you give blood and whatnot.\n",
      "fliers" : "Mostly concerning lost pets and church groups.\n",
      "lighting" : "It's a stark, and slightly too bright white light.\n",
    ]) );
    call_other(M_OBJ+"player_board", "foo");
    set("pre_exit_func", ([
      "south" : "wizonly"
    ]) );
  ::create() ;
  reset() ;
}

int wizonly() {
    if (!wizardp(TP)) {
	write("That door is only accessable to staff.\n");
	return 1;
    }

    return 0;
}
// EOF
