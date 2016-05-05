#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([
    "east" : BAATOR+"minauros/bog6.c",
    "south" : BAATOR+"minauros/bog12.c"]));
    reset();
}
