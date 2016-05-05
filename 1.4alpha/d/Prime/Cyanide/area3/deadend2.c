#include "garden.h"

inherit MAZE+"/deadendx.c";

void create() {
    ::create();

    set("exits", ([
      "west" : MAZE+"/maze5.c",
    ]) );
}
