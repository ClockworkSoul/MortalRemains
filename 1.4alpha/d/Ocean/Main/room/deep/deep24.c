#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep23.c",
      "east" : DEEP+"deep25.c",
    ]) );
    set("objects" , ([
      "octopus" : O_MON+"octopus.c",
    ]) );
    reset();

}
