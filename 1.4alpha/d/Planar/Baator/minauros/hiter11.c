#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "east" : BAATOR+"minauros/hiter12.c",
    "north" : BAATOR+"minauros/hiter6.c",
    "south" : BAATOR+"minauros/hiter16.c"
    ]));
}


