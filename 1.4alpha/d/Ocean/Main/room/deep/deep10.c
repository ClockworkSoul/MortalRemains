#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep9.c",
      "west" : DEEP+"deep11.c",
    ]) );
    set("objects" , ([
      "whale" : O_MON+"whale.c",
    ]) );
    reset();
}
