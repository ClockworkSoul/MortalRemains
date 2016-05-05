#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
        	::create();
 seteuid(getuid()) ;
     set ("exits", ([
     "east" : BAATOR+"dis/dcity5.c",
          "south" : BAATOR+"dis/dcity10.c"
          ]));
reset();
	}
