// Cyanide coded this.

#include "macrosoft.h"

#define LETTERS ({ "a", "b", "c", "d", "e" })

inherit MS_ELEV;

void create() {
    ::create();
    add("long", "\nA sign here reads \"MACROSOFT "+
      "LEGAL DEPT.\"\n");
    set("exits", ([ 
      "east" : FLOOR_4("c1.c"),
    ]) );
}

/* EOF */
