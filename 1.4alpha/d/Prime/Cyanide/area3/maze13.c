#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "down" : MAZE+"/maze12.c",
      "east" : MAZE+"/maze9.c",
      "south" : MAZE+"/maze10.c",
      "west" : MAZE+"/maze11.c",
    ]) );
}
