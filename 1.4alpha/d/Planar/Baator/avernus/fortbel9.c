#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
        ::create();
     set ("exits", ([
      "north" : BAATOR+"avernus/fortbel6.c",
      "south" : BAATOR+"avernus/fortbel12.c",
    "west" : BAATOR+"avernus/fortbel8.c"
    ]));
}
