#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    set ("exits", ([
        "north" : BAATOR+"avernus/lair6.c"
    ]));
    set("objects", ([
      "paragongreen" : BAATOR+"monsters/paragongreen",
      "paragonblack" : BAATOR+"monsters/paragonblack"
    ]) );
    reset();
}
