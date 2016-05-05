#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
    set ("exits", ([
        "north" : BAATOR+"avernus/fortbel11.c",
        "east" : BAATOR+"avernus/fortbel15.c",
        "west" : BAATOR+"avernus/fortbel13.c"
    ]));

}
