#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
     ::create();
     set ("exits", ([
     "east" : BAATOR+"dis/dplain18.c",
     "west" : BAATOR+"dis/dplain16.c"]));
}
