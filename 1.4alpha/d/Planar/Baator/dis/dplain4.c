#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "south" : BAATOR+"dis/dplain5.c",
     "north" : BAATOR+"dis/dplain3.c",
     "west" : BAATOR+"dis/dplain2.c",
     "east" : BAATOR+"dis/dplain9.c"]));
	}
