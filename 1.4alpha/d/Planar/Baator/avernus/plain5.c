#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"avernus/plain6.c",
      "south" : BAATOR+"avernus/plain9.c",
      "north" : BAATOR+"avernus/plain1.c"]));
}
