#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
    set ("exits", ([
      "west" : BAATOR+"avernus/fortbel2.c",
      "south" : BAATOR+"avernus/fortbel6.c"
    ]));
    set ("objects" , ([ 
      "amduscias" : BAATOR+"monsters/amduscias"
    ]));
    reset();
}

/* EOF */
