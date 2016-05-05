#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "east" : MAZE+"/maze9.c",
      "west" : MAZE+"/maze13",
      "up" : MAZE+"/maze11.c",
    ]) );
}
