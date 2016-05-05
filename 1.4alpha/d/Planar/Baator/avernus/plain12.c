#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain11.c",
      "south" : BAATOR+"avernus/plain16.c",
      "north" : BAATOR+"avernus/plain8.c"
      ]));
}
