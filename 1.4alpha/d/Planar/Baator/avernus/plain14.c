#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/plain13.c",
      "east" : BAATOR+"avernus/plain15.c",
      "south" : BAATOR+"avernus/plain18.c",
      "north" : BAATOR+"avernus/plain10.c"
      ]));
}
