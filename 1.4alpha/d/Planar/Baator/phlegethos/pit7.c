#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("exits", ([   
        "north" : BAATOR+"phlegethos/pit3.c",
        "south" : BAATOR+"phlegethos/pit10.c",
        "east" : BAATOR+"phlegethos/pit4.c"
    ]));
}


