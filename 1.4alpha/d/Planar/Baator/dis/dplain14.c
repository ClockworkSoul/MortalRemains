#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
        "east" : BAATOR+"dis/dplain15.c",
        "north" : BAATOR+"dis/dplain13.c"
    ]));
    set("objects" , (["osyluth" : BAATOR+"monsters/osyluth"]));
    reset();
}
