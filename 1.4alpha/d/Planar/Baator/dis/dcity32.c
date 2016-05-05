#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
     set ("exits", ([
     "west" : BAATOR+"dis/dcity31.c",
     "north" : BAATOR+"dis/dcity27.c"]));
    reset();
}
