#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "south" : BAATOR+"dis/dcity7.c"
    ]));
    reset();
}
