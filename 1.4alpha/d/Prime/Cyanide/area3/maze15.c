#include "garden.h"
#include <mudlib.h>

inherit MAZE+"/mazex.c";

void create() {
    ::create();

    set("exits", ([
      "west" : MAZE+"/maze14.c",
      "south" : MAZE+"/maze7.c",
      "southeast" : MAZE+"/gard_entrance.c",
    ]) );
}
