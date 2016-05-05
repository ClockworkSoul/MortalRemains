#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
    set ("exits", ([
        "south" : BAATOR+"dis/dplain7.c",
        "east" : BAATOR+"dis/dplain35.c"
    ]));
    set("objects" , ([
        "barbazu" : BAATOR+"monsters/barbazu",
		"osyluth" : BAATOR+"monsters/osyluth"
    ]));
    reset();
}
