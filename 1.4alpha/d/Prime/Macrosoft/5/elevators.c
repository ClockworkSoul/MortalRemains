// Cyanide coded this.

#include "macrosoft.h"

inherit MS_ELEV;

void create() {
    ::create();
    set("exits", ([ 
      "east" : FLOOR_5("a4.c"),
    ]) );
}

/* EOF */
