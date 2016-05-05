#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "north" : BAATOR+"dis/dplain9.c",
     "south" : BAATOR+"dis/dplain11.c",
     "west" : BAATOR+"dis/dplain5.c" ]));
	}
