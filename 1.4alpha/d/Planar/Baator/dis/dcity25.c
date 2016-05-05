#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"dis/dcity26.c",
      "north" : BAATOR+"dis/dcity20.c"
    ]));
    reset();
}
