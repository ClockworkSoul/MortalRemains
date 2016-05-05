#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "north" : BAATOR+"dis/dplain11.c",
      "east" : BAATOR+"dis/dplain13.c"
    ]));
    set("objects" , ([ 
        "barbazu" : BAATOR+"monsters/barbazu",
        "osyluth" : BAATOR+"monsters/osyluth"
    ]));
    reset();
}
