// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("cubestd");

void create() {
    ::create();
    set("exits", ([ 
    "south" : FLOOR_2("floor2.c"),
    ]) );
}

/* EOF */
