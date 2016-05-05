#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("exits", ([
    "west" : BAATOR+"minauros/bog1.c",
    "south" : BAATOR+"minauros/bog7.c"]));
    reset();
}
