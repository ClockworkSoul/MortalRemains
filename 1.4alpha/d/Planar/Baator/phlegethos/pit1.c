#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("exits", ([   
      "east" : BAATOR+"phlegethos/pit2.c",
      "south" : BAATOR+"phlegethos/pit5.c"
    ]));
    reset();
}


