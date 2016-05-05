#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "down" : MAZE+"/maze5.c",
      "up" : MAZE+"/maze9.c",
      "north" : MAZE+"/deadend3.c",
      "east" : MAZE+"/maze13.c",
      "southwest" : MAZE+"/maze11.c",
    ]) );
}
