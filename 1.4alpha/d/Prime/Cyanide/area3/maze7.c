#include "garden.h"

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "northeast" : MAZE+"/deadend1.c",
      "up" : MAZE+"/maze14.c",
      "east" : MAZE+"/maze8.c",
      "south" : MAZE+"/maze15.c",
      "west" : MAZE+"/maze6.c"
    ]) );
}
