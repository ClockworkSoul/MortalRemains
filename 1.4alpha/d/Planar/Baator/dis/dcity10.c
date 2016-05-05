#include <mudlib.h>
#include "baator.h"

inherit DCITY ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"dis/dcity11.c",
      "north" : BAATOR+"dis/dcity4.c"]));
    reset();
}
