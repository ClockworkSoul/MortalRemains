#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"dis/dcity2.c",
      "south" : BAATOR+"dis/dcity5.c"
    ]));
    reset();
}
