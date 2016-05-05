#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c";

void create() {    
    ::create();
    set ("exits", ([   
    "east" : BAATOR+"minauros/hiter18.c",
    "north" : BAATOR+"minauros/hiter12.c",
    "south" : BAATOR+"minauros/hiter22.c"
    ]));
}