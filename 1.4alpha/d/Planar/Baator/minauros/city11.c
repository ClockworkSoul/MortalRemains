#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([       
        "south" : BAATOR+"minauros/city18.c",
        "north" : BAATOR+"minauros/city5.c",
        "east" : BAATOR+"minauros/city12.c"
    ]));
}


