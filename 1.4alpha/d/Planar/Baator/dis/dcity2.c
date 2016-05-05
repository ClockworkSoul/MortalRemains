#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "west" : BAATOR+"dis/dcity1.c",
     "south" : BAATOR+"dis/dcity6.c"
     ]));
reset();
	}
