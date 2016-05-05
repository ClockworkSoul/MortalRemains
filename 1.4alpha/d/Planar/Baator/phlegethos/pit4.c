#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("exits", ([   
        "east" : BAATOR+"phlegethos/out10.c",
        "west" : BAATOR+"phlegethos/pit7.c"
    ]));
}


