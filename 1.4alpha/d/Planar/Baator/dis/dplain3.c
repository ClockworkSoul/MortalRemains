#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "south" : BAATOR+"dis/dplain4.c",
      "east" : BAATOR+"dis/dplain8.c"
    ]));
    set("objects" , ([ 
      "spinagon" : BAATOR+"monsters/spinagon"
    ]));
    reset();
}
