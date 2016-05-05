#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "west" : BAATOR+"minauros/hiter13.c",
    "north" : BAATOR+"minauros/hiter9.c",
    "south" : BAATOR+"minauros/hiter19.c"
    ]));
}