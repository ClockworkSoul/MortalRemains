#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "west" : BAATOR+"dis/dcity4.c",
          "north" : BAATOR+"dis/dcity1.c"]));
reset();
	}
