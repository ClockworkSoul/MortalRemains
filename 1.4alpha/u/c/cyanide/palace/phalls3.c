// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    set("exits", ([
      "north" : MAIN+"/phallcs.c",
      "west" : MAIN+"/phalls2.c",
    ]) );
}

/* EOF */

