#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {
    ::create();
    add ("long", "You have wandered into a dead-end.\n");
    set ("exits", ([   
    "north" : BAATOR+"minauros/city8.c"
    ]));
}


