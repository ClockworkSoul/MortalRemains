#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
    set ("exits", ([
      "north" : BAATOR+"avernus/fortbel2.c"
      ]));
}
