#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortbel16.c" ;

void create() {
    ::create();
	seteuid(getuid()) ;
     set ("exits", ([
       "west" : BAATOR+"avernus/fortbel16.c",
       "east" : BAATOR+"avernus/fortbel16.c"
     ]));
}
