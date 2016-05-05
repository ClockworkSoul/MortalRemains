#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("exits", ([   
        "east" : BAATOR+"phlegethos/pit3.c",
        "west" : BAATOR+"phlegethos/pit1.c"
    ]));
}


