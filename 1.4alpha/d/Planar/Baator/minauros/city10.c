#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {     
    ::create();
    set ("exits", ([   
      "south" : BAATOR+"minauros/city17.c",
      "north" : BAATOR+"minauros/city4.c"
    ]));
}


