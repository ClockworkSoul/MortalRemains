#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "west" : BAATOR+"minauros/bog16.c",
    "east" : BAATOR+"minauros/city15.c",  
    "north" : BAATOR+"minauros/bog10.c",
    "south" : BAATOR+"minauros/bog23.c"]));
    reset();
}
