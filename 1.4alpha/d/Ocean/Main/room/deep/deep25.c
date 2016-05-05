#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep24.c",
      "east" : DEEP+"deep_sea.c",
    ]) );
    set("objects" , ([
      "catfish" : O_MON+"cat.c",
      "shark" : O_MON+"shark.c",
      "anemone" : O_MON+"anemone.c",
    ]) );
    reset();
}
