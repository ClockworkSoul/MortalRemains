#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "south" : DEEP+"deep4.c",
      "north" : DEEP+"deep6.c",
    ]) );
    set("objects" , ([
      "octopus" : O_MON+"octopus.c",
    ]) );
    reset();
}
