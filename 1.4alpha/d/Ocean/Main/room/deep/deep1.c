#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep_sea.c",
      "east" : DEEP+"deep2.c",
    ]) );
    set("objects" , ([
      "catfish" : O_MON+"cat.c",
      "jellyfish" : O_MON+"jfish.c",
      "girl" : O_MON+"diver1.c",
    ]) );
    reset();
}

