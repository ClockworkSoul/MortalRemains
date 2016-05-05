#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "northeast" : MAZE+"/maze7.c",
      "south" : MAZE+"/maze7.c",
      "west" : MAZE+"/maze15.c",
    ]) );
}
