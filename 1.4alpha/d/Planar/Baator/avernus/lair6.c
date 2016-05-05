#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "north" : BAATOR+"avernus/lair3.c",
      "south" : BAATOR+"avernus/lair9.c",
      "east" : BAATOR+"avernus/ave6.c",
      "west" : BAATOR+"avernus/lair5.c"
      ]));
}
