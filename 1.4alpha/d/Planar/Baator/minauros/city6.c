#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("exits", ([   
      "north" : BAATOR+"minauros/city3.c",
      "south" : BAATOR+"minauros/city12.c",
      "east" : BAATOR+"minauros/city7.c"
    ]));
}


