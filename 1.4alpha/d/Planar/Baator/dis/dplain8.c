#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "north" : BAATOR+"dis/dplain7.c",
     "south" : BAATOR+"dis/dplain9.c",
     "west" : BAATOR+"dis/dplain3.c" ]));
	}
