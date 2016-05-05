#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {
    ::create();
    set ("exits", ([   
    "south" : BAATOR+"minauros/city13.c",
    "west" : BAATOR+"minauros/city6.c",
    "east" : BAATOR+"minauros/city8.c"
    ]));
}


