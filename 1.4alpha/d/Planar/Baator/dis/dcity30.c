#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "north" : BAATOR+"dis/dcity24.c",
      "west" : BAATOR+"dis/dcity29.c"
    ]));
    reset();
}
