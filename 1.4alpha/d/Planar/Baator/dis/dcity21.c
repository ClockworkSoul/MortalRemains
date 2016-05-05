#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();    
    set ("exits", ([    
        "west" : BAATOR+"dis/dcity20.c",
        "north" : BAATOR+"dis/dcity16.c"
    ]));
    reset();
}
