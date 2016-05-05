#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
        ::create();
    set ("exits", ([
        "west" : BAATOR+"avernus/fortbel1.c",
        "east" : BAATOR+"avernus/fortbel3.c",
        "south" : BAATOR+"avernus/fortbel5.c"
    ]));
}
