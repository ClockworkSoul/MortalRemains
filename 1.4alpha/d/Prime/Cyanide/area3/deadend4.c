#include "garden.h"

inherit MAZE+"/deadendx.c";

void create() {
    ::create();

    set("exits", ([
      "north" : MAZE+"/maze8.c",
    ]) );
}
