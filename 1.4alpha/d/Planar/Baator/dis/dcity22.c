#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();    
    set ("exits", ([    
        "south" : BAATOR+"dis/dcity27.c",
        "north" : BAATOR+"dis/dcity17.c"
    ]));
    reset();
}
