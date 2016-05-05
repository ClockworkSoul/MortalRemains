#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "On A Rope Bridge");
    set("long", @EndText
Somehow, you managed to work up the courage to attempt to cross the
frail-looking rope bridge. It's barely wide enough for one person, and
several of the heat-blackened planks that make up its walkway are missing
or damaged. About twenty meters below you a river of lava flows like water,
making the air on this bridge excruciatingly hot.
EndText
    );
    set("exits", ([
        "north" : PHLEGETHOS+"out06.c",
        "south" : PHLEGETHOS+"out08.c"
    ]) );
    reset();
}

void init() {
    if(TP->receive_damage(10, "fire", TO, 0))
        tell_object(TO, "Your lungs burn in the incredible heat!\n");
}