#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dplain22.c",
     "north" : BAATOR+"dis/dplain24.c"
     ]));
}
