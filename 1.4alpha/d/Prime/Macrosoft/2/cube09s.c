// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("cubestd");

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_2("floor9.c"),
    ]) );
}

/* EOF */
