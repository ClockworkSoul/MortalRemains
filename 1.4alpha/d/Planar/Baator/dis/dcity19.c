#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dcity24.c",
     "north" : BAATOR+"dis/dcity14.c"]));
reset();
	}
