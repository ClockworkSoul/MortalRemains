#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dcity32.c",
     "north" : BAATOR+"dis/dcity22.c"
     ]));
reset();
	}
