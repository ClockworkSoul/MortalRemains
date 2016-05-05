// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {

    ::create();
    torches = 3;
    set("exits", ([
      "west" : MAIN+"/ballroom.c",
      "north" : MAIN+"/phalln3.c",
      "south" : MAIN+"/spireante.c",
    ]) );
}

/* EOF */

