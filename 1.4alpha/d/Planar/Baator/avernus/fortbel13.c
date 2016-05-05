#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
        ::create();
     set ("exits", ([
      "north" : BAATOR+"avernus/fortbel10.c",
       "east" : BAATOR+"avernus/fortbel14.c"
     ]));
}
