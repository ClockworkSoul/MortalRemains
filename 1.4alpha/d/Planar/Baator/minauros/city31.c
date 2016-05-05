#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/city25.c",
    "south" : BAATOR+"minauros/city34.c",
    "west" : BAATOR+"minauros/city30.c"
    ]));
}