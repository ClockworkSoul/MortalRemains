#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
    "north" : BAATOR+"minauros/city32.c",
    "south":BAATOR+"minauros/city36.c",
    "west" : BAATOR+"minauros/city34.c"]));
}


