#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
          "north" : BAATOR+"dis/dcity28.c"
          ]));
reset();
	}
