#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/city26.c",
    "south" : BAATOR+"minauros/city35.c",
    "east" : BAATOR+"minauros/city33.c"
    ]));
}


