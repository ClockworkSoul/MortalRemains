#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "north" : BAATOR+"avernus/lair2.c",
      "south" : BAATOR+"avernus/lair8.c",
      "east" : BAATOR+"avernus/lair6.c",
      "west" : BAATOR+"avernus/lair4.c"
    ]));
    set("objects", ([
      "tiamat" : BAATOR+"monsters/tiamat",
    ]) );
    reset();
}
