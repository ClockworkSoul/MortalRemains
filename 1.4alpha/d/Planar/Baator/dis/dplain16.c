#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set ("exits", ([
      "east" : BAATOR+"dis/dplain17.c",
      "west" : BAATOR+"dis/dplain15.c"]));
    set("objects", ([
      "ha,atula" : BAATOR+"monsters/hamatula"  
    ]) );
    reset();
}
