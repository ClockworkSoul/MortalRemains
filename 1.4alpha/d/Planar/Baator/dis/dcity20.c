#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("exits", ([        
        "east" : BAATOR+"dis/dcity21.c",
        "south" : BAATOR+"dis/dcity25.c"
    ]) );
    reset();
}
