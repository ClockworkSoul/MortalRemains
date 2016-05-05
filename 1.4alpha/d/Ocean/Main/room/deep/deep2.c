#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep1.c",
      "east" : DEEP+"deep3.c",
    ]) );
    set("objects" , ([
      "whale" : O_MON+"whale.c",
    ]) );
    reset();
}
