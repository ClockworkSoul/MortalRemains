#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
        ::create();
     set ("exits", ([
       "south" : BAATOR+"avernus/fortbel14.c"
       ]));
}
