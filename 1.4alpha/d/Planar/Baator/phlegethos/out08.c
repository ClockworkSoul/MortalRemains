#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "South of a River of Lava");
    set("long", @EndText
You are standing on the ridge of a small chasm through which a fluid river
of lava flows. The chasm runs from the west to the east, and a small, 
frail-looking rope bridge crosses the river here.
EndText
    );
    set("exits", ([
        "north" : PHLEGETHOS+"out07.c",
        "west" : PHLEGETHOS+"out09.c"
    ]) );
    reset();
}