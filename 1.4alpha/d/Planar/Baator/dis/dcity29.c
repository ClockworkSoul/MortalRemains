#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
        "east" : BAATOR+"dis/dcity30.c",
        "west" : BAATOR+"dis/dcity28.c"
    ]));
    reset();
}
