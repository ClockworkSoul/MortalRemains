#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "west" : BAATOR+"minauros/bog6.c",
    "east" : BAATOR+"minauros/bog8.c",  
    "north" : BAATOR+"minauros/bog2.c",
    "south" : BAATOR+"minauros/bog14.c"]));
    reset();
}
