#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"dis/dplainstd.c" ;

void create() {
    ::create();
    set("objects" , (["osyluth" : BAATOR+"monsters/osyluth"]));
    set ("exits", ([
      "east" : BAATOR+"dis/dplain33.c",
      "south" : BAATOR+"dis/dplain35.c"]));
    reset();
}
