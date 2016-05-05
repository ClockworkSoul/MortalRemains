// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    torches = 3;
    set("exits", ([
      "south" : MAIN+"/phalls3.c",
      "north" : MAIN+"/spireante.c",
      "west" : MAIN+"/kitchen.c",
    ]) );
}

/* EOF */

