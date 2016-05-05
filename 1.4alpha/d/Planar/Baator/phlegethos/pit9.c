#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("exits", ([   
        "east" : BAATOR+"phlegethos/pit10.c",
        "west" : BAATOR+"phlegethos/pit8.c"
    ]));
}