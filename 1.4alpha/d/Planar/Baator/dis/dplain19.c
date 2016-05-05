#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "north" : BAATOR+"dis/dplain20.c",
     "west" : BAATOR+"dis/dplain18.c"
     ]));
    set("objects" , (["osyluth" : BAATOR+"monsters/osyluth"]));
    reset();
}
