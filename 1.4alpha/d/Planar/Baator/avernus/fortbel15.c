#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/fortstd.c";

void create() {
    ::create();
    set ("exits", ([
      "down" : "/d/Planar/Abyss/Nazi/library/library",
      "north" : BAATOR+"avernus/fortbel12.c",
      "west" : BAATOR+"avernus/fortbel14.c"
    ]));
    set ("objects" , ([ 
      "malphas" : BAATOR+"monsters/malphas"
    ]));    
    reset();
}
