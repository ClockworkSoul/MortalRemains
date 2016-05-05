#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dplain31.c",
     "west" : BAATOR+"dis/dplain33.c"]));
     set("objects" , (["hamatula" : BAATOR+"monsters/hamatula"]));
    reset();
}
