#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([     
    "west" : BAATOR+"minauros/bog24.c"
    ]));
    reset();
}
