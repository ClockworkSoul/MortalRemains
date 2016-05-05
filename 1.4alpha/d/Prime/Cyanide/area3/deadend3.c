#include "garden.h"

inherit MAZE+"/deadendx.c";

void create() {
    ::create();

    set("exits", ([
      "south" : MAZE+"/maze12.c",
    ]) );
}
