#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "north" : BAATOR+"dis/dplain10.c",
     "south" : BAATOR+"dis/dplain12.c"
     ]));
}