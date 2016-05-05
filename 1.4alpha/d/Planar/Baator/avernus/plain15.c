#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain14.c",
      "east" : BAATOR+"avernus/plain16.c",
      "south" : BAATOR+"avernus/plain19.c",
      "north" : BAATOR+"avernus/plain11.c"
      ]));
}
