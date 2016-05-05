#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dcity31.c",
     "west" : BAATOR+"dis/dcity25.c"
     ]));
reset();
	}
