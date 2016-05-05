#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "north" : MAZE+"/maze6.c",
      "west" : MAZE+"/maze12.c",
      "south" : MAZE+"/maze13.c",
      "east" : MAZE+"/maze10.c",
      "up" : MAZE+"/maze11.c"
    ]) );
}
