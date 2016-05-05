#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "south" : BAATOR+"avernus/lair5.c",
      "west" : BAATOR+"avernus/lair1.c"
    ]));
}
