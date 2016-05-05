#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"phlegethos/pitstd.c";

void create() {
    ::create();
    set ("exits", ([   
      "west" : BAATOR+"phlegethos/pit9.c",
      "north" : BAATOR+"phlegethos/pit7.c"
    ]));
    reset();
}
