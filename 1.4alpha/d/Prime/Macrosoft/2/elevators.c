// Cyanide coded this.

#include "macrosoft.h"

inherit MS_ELEV;

void create() {
    ::create();
    set("exits", ([ 
      "east" : FLOOR_2("floor6.c"),
    ]) );
}

/* EOF */
