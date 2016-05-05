#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dcity32.c",
     "north" : BAATOR+"dis/dcity26.c"]));
reset();
	}
