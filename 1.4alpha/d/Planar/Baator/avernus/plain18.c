#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("exits", ([
      "west" : BAATOR+"avernus/plain17.c",
      "east" : BAATOR+"avernus/plain19.c",
      "north" : BAATOR+"avernus/plain14.c"
      ]));
}
