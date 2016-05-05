#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
    set ("exits", ([
        "south" : BAATOR+"dis/dplain28.c",
        "west" : BAATOR+"dis/dplain30.c"
    ]));
    set("objects" , (["osyluth" : BAATOR+"monsters/osyluth"]));
    reset();
}
