#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/plainstd.c" ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("exits", ([
      "west" : BAATOR+"avernus/plain18.c",
      "east" : BAATOR+"avernus/plain20.c",
      "north" : BAATOR+"avernus/plain15.c"
      ]));
}
