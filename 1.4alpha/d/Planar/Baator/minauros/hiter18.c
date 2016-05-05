#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "east" : BAATOR+"minauros/hiter19.c",
    "west" : BAATOR+"minauros/hiter17.c",
    "south" : BAATOR+"minauros/hiter23.c"
    ]));
}