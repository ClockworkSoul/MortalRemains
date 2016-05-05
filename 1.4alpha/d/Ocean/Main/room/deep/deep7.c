#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "south" : DEEP+"deep6.c",
      "north" : DEEP+"deep8.c",
    ]) );
    set("objects" , ([
      "shark" : O_MON+"shark.c",
    ]) );
    reset();
}
