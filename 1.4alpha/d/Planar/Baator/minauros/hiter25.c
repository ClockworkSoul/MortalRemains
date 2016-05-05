#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/hiter20.c",
    "west" : BAATOR+"minauros/hiter24.c"
    ]));
}


