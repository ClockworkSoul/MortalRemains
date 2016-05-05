#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
        "north" : BAATOR+"dis/dplain6.c",
        "south" : BAATOR+"dis/dplain8.c"]));
}
