#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "east" : BAATOR+"minauros/bog19.c",  
    "north" : BAATOR+"minauros/bog12.c",
    "south" : BAATOR+"minauros/bog24.c"]));
    reset();
}
