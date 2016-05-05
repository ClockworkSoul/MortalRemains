#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([     
    "east" : BAATOR+"minauros/bog25.c",
    "north" : BAATOR+"minauros/bog18.c"
    ]));
    reset();
}
