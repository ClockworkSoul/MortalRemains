#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "west" : BAATOR+"minauros/hiter2.c", 
    "east" : BAATOR+"minauros/hiter4.c"
    ]));    
}


