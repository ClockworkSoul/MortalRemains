#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("exits", ([
      "north" : BAATOR+"avernus/lair5.c",
      "west" : BAATOR+"avernus/lair7.c"
      ]));
}
