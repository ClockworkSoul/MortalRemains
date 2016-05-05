#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dplain19.c",
     "east" : BAATOR+"dis/dplain21.c"
     ]));
}
