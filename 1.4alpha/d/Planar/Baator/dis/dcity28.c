#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dcity29.c",
     "south" : BAATOR+"dis/dcity33.c",
     "north" : BAATOR+"dis/dcity23.c"
     ]));
reset();
	}
