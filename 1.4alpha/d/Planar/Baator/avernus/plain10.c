#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain9.c",
      "east" : BAATOR+"avernus/plain11.c",
      "south" : BAATOR+"avernus/plain14.c",
      "north" : BAATOR+"avernus/plain6.c"
    ]));
}
