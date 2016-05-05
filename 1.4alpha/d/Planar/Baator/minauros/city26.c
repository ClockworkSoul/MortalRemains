#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "south" : BAATOR+"minauros/city32.c",
    "north" : BAATOR+"minauros/city19.c"]));
}


