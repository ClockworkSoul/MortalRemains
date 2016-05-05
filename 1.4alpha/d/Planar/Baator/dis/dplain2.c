#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "west" : BAATOR+"dis/dplain1.c",
     "east" : BAATOR+"dis/dplain4.c"
     ]));
}
