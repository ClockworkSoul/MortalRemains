#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "south" : BAATOR+"dis/dcity30.c",
      "north" : BAATOR+"dis/dcity19.c"
    ]));
    reset();
}
