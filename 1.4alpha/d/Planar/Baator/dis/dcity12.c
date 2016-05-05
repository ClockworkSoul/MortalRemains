#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dcity17.c",
     "north" : BAATOR+"dis/dcity6.c"]));
reset();
	}
