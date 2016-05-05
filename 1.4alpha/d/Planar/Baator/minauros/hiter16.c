#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/hiter11.c",
    "south" : BAATOR+"minauros/hiter21.c"
    ]));
}