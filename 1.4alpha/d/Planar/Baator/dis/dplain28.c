#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dplain27.c",
     "north" : BAATOR+"dis/dplain29.c"]));
}
