#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/hiter5.c",
    "south" : BAATOR+"minauros/hiter15.c"
    ]));
}