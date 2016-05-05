#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {
    ::create();
    set ("exits", ([   
      "west" : BAATOR+"minauros/bog15.c",
      "east" : BAATOR+"minauros/bog17.c",  
      "north" : BAATOR+"minauros/bog9.c",
      "south" : BAATOR+"minauros/bog22.c"]));
    reset();
}
