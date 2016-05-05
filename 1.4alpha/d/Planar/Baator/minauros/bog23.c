#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([     
    "west" : BAATOR+"minauros/bog22.c",
    "north" : BAATOR+"minauros/bog17.c"]));
    reset();
}
