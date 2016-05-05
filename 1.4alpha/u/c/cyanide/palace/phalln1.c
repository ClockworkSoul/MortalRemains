// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    torches = 3;
    set("exits", ([
      "east" : MAIN+"/ballroom.c",
      "northeast" : MAIN+"/phalln2.c",
      "south" : MAIN+"/room8'5.c",
    ]) );
}

/* EOF */

