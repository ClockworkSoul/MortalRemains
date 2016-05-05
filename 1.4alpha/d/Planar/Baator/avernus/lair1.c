#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"avernus/lair2.c"
      ]));
}
