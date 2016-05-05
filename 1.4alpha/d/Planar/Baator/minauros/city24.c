#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/city17.c",
    "east" : BAATOR+"minauros/city25.c"
    ]));
}


