#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dcity12.c",
          "north" : BAATOR+"dis/dcity2.c"]));
reset();
	}
