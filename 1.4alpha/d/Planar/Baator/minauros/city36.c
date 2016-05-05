#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
      "north" : BAATOR+"minauros/city35.c"
    ]));
}


