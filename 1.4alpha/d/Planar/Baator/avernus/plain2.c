#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain1.c",
      "south" : BAATOR+"avernus/plain6.c",
      "east" : BAATOR+"avernus/plain3.c"
      ]));
}
