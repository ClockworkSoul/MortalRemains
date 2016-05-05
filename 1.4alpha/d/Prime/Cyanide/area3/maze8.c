#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "northeast" : MAZE+"/maze7.c",
      "southeast" : MAZE+"/deadend4.c",
    ]) );
}
