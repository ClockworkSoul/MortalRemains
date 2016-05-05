#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
    set ("exits", ([
     "north" : BAATOR+"dis/dplain4.c",
     "east" : BAATOR+"dis/dplain10.c"]));
    set("objects" , ([ "spinagon" : BAATOR+"monsters/spinagon" ]));
    reset();
}
