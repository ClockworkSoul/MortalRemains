#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dplain29.c",
     "west" : BAATOR+"dis/dplain31.c"]));
}
