#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c";

void create() {    
    ::create();
    set ("exits", ([   
      "west" : BAATOR+"minauros/hiter11.c",
      "north" : BAATOR+"minauros/hiter7.c",
      "south" : BAATOR+"minauros/hiter17.c" 
    ]));
}
