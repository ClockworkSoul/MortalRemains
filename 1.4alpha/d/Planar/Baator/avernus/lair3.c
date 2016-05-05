#include <mudlib.h>
#include "baator.h"

inherit BAATOR+"avernus/lairstd.c" ;

void create() {
    ::create();
    set ("exits", ([
        "south" : BAATOR+"avernus/lair6.c"
    ]) );
    set ("objects" , ([ 
      "paragonblue" : BAATOR+"monsters/paragonblue",
      "paragonwhite" : BAATOR+"monsters/paragonwhite"
    ]));
    reset();
}
