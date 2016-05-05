#include "garden.h"

inherit ROOM;

void create() {
    ::create();
    set("author", "Cyanide");
    seteuid(getuid());
    set("light", 1);
    set("short", "Odd Room");
    set("long", @EndLong
You are standing at the terminus of a long basalt hallway.
To the northeast, a black hallway leads into inky
darkness; to the east... sunlight!
EndLong
    );
    set("exits", ([
      "northeast" : MAZE+"/maze15.c",
      "east" : MAZE+"/garden01.c",
    ]) );
}
