#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "north" : DEEP+"deep21.c",
      "east" : DEEP+"deep23.c",
    ]) );
    set("objects" , ([
      "shark" : O_MON+"shark.c",
      "fish" : O_MON+"fish.c",
    ]) );
    reset();
}
