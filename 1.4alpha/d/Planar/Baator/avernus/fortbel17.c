#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortbel16.c" ;

void create() {
    ::create();
	seteuid(getuid()) ;
     set ("exits", ([
       "south" : BAATOR+"avernus/fortbel16.c",
       "north" : BAATOR+"avernus/fortbel19.c"
     ]));
}
