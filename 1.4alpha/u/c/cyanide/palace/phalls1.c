// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    set("exits", ([
      "east" : MAIN+"/dininghall.c",
      "southeast" : MAIN+"/phalls2.c",
      "north" : MAIN+"/room8'5.c",
    ]) );
}

/* EOF */

