#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set("objects", ([ "pit fiend" : BAATOR+"monsters/pit_fiend" ]));
    set ("exits", ([   
        "west" : BAATOR+"phlegethos/pit2.c",
        "south" : BAATOR+"phlegethos/pit7.c"
    ]));
    reset();
}


