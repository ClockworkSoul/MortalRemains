#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "north" : DEEP+"deep18.c",
      "south" : DEEP+"deep20.c",
    ]) );
    set("objects" , ([
      "octopus" : O_MON+"octopus.c",
      "jellyfish" : O_MON+"jfish.c",
    ]) );
    reset();
}
