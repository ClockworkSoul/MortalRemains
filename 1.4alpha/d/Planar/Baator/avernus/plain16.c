#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain15.c",
      "south" : BAATOR+"avernus/plain20.c",
      "north" : BAATOR+"avernus/plain12.c"
      ]));
}
