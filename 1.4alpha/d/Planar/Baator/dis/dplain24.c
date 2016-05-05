#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
        "south" : BAATOR+"dis/dplain23.c",
        "north" : BAATOR+"dis/dplain25.c"
    ]));
    set("objects" , (["hamatula" : BAATOR+"monsters/hamatula"]));
    reset();
}
