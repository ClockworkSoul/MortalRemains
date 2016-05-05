#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
     set ("exits", ([
      "north" : BAATOR+"avernus/fortbel9.c",
       "south" : BAATOR+"avernus/fortbel15.c"
     ]));
}
