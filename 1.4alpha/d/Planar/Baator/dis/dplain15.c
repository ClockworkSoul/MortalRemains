#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dplain16.c",
     "west" : BAATOR+"dis/dplain14.c"
     ]));
}
