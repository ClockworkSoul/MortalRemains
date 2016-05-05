#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dplain14.c",
     "west" : BAATOR+"dis/dplain12.c"
     ]));
    reset();
}
