#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
        ::create();
     set ("exits", ([
      "north" : BAATOR+"avernus/fortbel7.c",
     "south" : BAATOR+"avernus/fortbel13.c"
     ]));
   set("objects", ([
  ]) ) ;
  reset() ;
}
