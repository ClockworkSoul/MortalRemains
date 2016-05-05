#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/city6.c",
    "west" : BAATOR+"minauros/city11.c"
    ]));
}


