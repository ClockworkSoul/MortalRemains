#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain5.c",
      "east" : BAATOR+"avernus/plain7.c",
      "south" : BAATOR+"avernus/plain2.c",
      "north" : BAATOR+"avernus/plain10.c"
      ]));
}
