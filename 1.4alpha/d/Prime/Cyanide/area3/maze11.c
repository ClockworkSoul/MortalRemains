#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "northwest" : MAZE+"/maze13.c",
      "down" : MAZE+"/maze10.c",
      "southwest" : MAZE+"/maze12.c",
      //"northeast" : TO_FGRATING_ROOM
    ]) );
}
