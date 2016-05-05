#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "River Edge");
    set("long", @EndText
You are on the southern edge of a narrow chasm thorough which flows an
excruciating hot river of lava, the heat from which is nearly unbearable.
Far to the north, through the superheated air, you can make out a massive
volcano atop which seems to be a similarly massive city. The river here makes
a turn to the southwest and eventually empties into a large lake.
EndText
    );
    set("exits", ([
        "east" : PHLEGETHOS+"out08.c",
        "southwest" : PHLEGETHOS+"out10.c"
    ]) );
    reset();
}