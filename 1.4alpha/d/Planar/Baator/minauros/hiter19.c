#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([       
        "north" : BAATOR+"minauros/hiter14.c",
        "west" : BAATOR+"minauros/hiter18.c"
    ]));
}


