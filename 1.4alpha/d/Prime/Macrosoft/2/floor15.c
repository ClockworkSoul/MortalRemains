// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
    "west" : FLOOR_2("floor14.c"),
    "north" : FLOOR_2("floor10.c"),
    ]) );
}

/* EOF */
