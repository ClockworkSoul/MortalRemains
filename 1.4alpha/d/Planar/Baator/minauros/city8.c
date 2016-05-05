#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
      "south" : BAATOR+"minauros/city14.c",
      "west" : BAATOR+"minauros/city7.c"
    ]));
}


