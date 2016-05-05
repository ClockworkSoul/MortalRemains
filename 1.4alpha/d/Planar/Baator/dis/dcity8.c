#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
   	::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dcity9.c",
     "west" : BAATOR+"dis/dcity7.c"
     ]));
    reset();
}
