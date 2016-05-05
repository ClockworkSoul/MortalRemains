#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
  	::create();
    set ("exits", ([        
        "south" : BAATOR+"dis/dcity13.c",
        "east" : BAATOR+"dis/dcity8.c",
        "north" : BAATOR+"dis/dcity3.c"
    ]));
    reset();
}
