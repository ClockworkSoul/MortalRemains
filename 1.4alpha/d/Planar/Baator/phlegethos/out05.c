#include "baator.h"

inherit BAATOR+"phlegethos/phstd.c";

void create() {
    ::create();
    set("short", "A Grand View");
    set("long", @EndText
As you round a bend in the path, an incredible sight floods your vision.
From this high point, roughly halfway up the largest volcano in the region,
you can see a grand "lavafall", hundreds of feet high, freely falling from
the southernmost part of the volcano and forming a river of fire flowing to
the south for several miles until it splits. You can also see great hills
of ash, vast lakes and rivers of fire, and huge pools of smoking dung.
EndText
    );
    set("exits", ([
        "northwest" : PHLEGETHOS+"out04.c",
        "south" : PHLEGETHOS+"out06.c"
    ]) );
    reset();
}