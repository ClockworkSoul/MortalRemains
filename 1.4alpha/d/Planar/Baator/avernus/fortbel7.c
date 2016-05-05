#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
     set ("exits", ([
      "west" : BAATOR+"avernus/ave2.c",
      "north" : BAATOR+"avernus/fortbel4.c",
    "south" : BAATOR+"avernus/fortbel10.c"
    ]));
}
