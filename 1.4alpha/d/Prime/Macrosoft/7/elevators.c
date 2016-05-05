// Cyanide coded this.

#include "macrosoft.h"

inherit MS_ELEV;

void create() {
    ::create();
    set("exits", ([ 
      "north" : FLOOR_7("tjunction.c"),
    ]) );
}

/* EOF */
