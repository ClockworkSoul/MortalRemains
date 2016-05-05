#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortbel16.c" ;

void create() {
     ::create();
     set ("exits", ([
       "north" : BAATOR+"avernus/fortbel16.c",
       "south" : BAATOR+"avernus/fortbel17.c"
     ]));
}
