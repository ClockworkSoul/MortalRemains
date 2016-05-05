#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "south" : BAATOR+"minauros/city31.c",
    "west" : BAATOR+"minauros/city24.c"
    ]));
}


