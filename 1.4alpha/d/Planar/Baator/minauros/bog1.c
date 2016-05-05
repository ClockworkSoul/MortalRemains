#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([
    "east" : BAATOR+"minauros/bog2.c"
    ]));
    reset();
}
