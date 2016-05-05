#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "River Edge");
    set("long", @EndText
You are and the edge of a fiery lake of lava which runs from the northeast
to the west from here. The land around is a scorched brown wasteland, lit
only by the leaping flames from the lava all around. To the west the path
leads to the very edges of the pit of flames itself.
EndText
    );
    set("exits", ([
        "west" : PHLEGETHOS+"pit4.c",
        "northeast" : PHLEGETHOS+"out09.c"
    ]) );
    reset();
}