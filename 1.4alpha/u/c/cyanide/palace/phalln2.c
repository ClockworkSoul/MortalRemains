// A room in the Palace of Cyanide

#include "main.h"

inherit MAIN+"/phallstd.c";

void create() {
    ::create();
    set("exits", ([
      "southwest" : MAIN+"/phalln1.c",
      "east" : MAIN+"/phalln3.c",
    ]) );
}

/* EOF */

