// Template

#include "macrosoft.h"

inherit MS_STD_ROOM;

void create() {
    ::create();
    set("forbidden", 1);
    set("short", "In Front of the Macrosoft HQ");
    set("long", wrap(
	"You are standing in front of the massive black building "+
	"of glass and steel which houses the corporate "+
	"headquarters of the multinational Macrosoft Corporation. "+
	"A revolving door leads into the building to the north."
      ) );
    set("exits", ([
      "north" : FLOOR_1("lobby.c"),
      "south" : "/d/Prime/Central/room/road3_0.c",
    ]) );
    call_other(MS_OBJ("MS_board.c"), "BITE_ME_BILL");
    find_object_or_load(FLOOR_3("elevators.c"));
}

/* EOF */
