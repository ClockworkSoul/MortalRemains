#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep11.c",
      "west" : DEEP+"deep13.c",
    ]) );
    set("objects" , ([
      "octopus" : O_MON+"octopus.c",
      "stingray" : O_MON+"stingray.c",
      "eleceel" : O_MON+"eleceel.c",
    ]) );
    reset();
}
