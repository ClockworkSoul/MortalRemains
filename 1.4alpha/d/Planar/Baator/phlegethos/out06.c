#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "Volcano Base");
    set("long", @EndText
This is the base of a massive volcano set in the middle of a vast, smoking
plain in a realm of smoking volcanoes, gauging fires and hills of ash. The
sky is a dark, starless void, and the land is weirdly lit by leaping flames.
A river of lava cuts through the path to the south, crossed by what appears
to be an unsturdy rope bridge.
EndText
    );
    set("exits", ([
        "north" : PHLEGETHOS+"out05.c",
        "south" : PHLEGETHOS+"out07.c"
    ]) );
    set("item_desc", ([
    "bridge" : "You wonder why it hasn't burned away from the heat.\n",
    ]) );
    reset();
}