#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {
    ::create();    
    set ("exits", ([   
    "west" : BAATOR+"minauros/hiter3.c",  
    "east" : BAATOR+"minauros/hiter5.c"
    ]));
}