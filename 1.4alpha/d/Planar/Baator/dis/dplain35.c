#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "north" : BAATOR+"dis/dplain34.c",
     "west" : BAATOR+"dis/dplain6.c"]));
	}
