#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "east" : BAATOR+"minauros/bog7.c",  
    "west" : BAATOR+"minauros/bog5.c",
    "south" : BAATOR+"minauros/bog13.c"]));
    reset();
}
