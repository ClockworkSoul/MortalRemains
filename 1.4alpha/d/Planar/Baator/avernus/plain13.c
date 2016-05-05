#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"avernus/plain14.c",
      "south" : BAATOR+"avernus/plain17.c",
      "north" : BAATOR+"avernus/plain9.c"
   ]));
}
