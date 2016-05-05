#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dplain25.c",
     "north" : BAATOR+"dis/dplain27.c"]));
}
