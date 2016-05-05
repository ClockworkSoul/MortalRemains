// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    set("exits", ([
      "east" : MAIN+"/phalls3.c",
      "northwest" : MAIN+"/phalls1.c",
    ]) );
}

/* EOF */

