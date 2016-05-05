#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([     
    "west" : BAATOR+"minauros/bog18.c",
    "north" : BAATOR+"minauros/bog13.c",
    "east" : BAATOR+"minauros/bog20.c"]));
    reset();
}
