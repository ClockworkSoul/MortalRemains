// Cyanide coded this.   
// 3 August 1999

#include "macrosoft.h"

inherit FLOOR_2("floorstd");

void create() {
    ::create();
    set("exits", ([ 
    "west" : FLOOR_2("floor4.c"),
    "south" : FLOOR_2("floor10.c"),
    ]) );
}

/* EOF */
