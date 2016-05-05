// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    set("exits", ([
      "west" : MAIN+"/phalln2.c",
      "south" : MAIN+"/phallcn.c",
    ]) );
}

/* EOF */

