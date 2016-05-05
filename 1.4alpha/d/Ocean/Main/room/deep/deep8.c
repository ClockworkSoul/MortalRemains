#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "south" : DEEP+"deep7.c",
      "north" : DEEP+"deep9.c",
    ]) );
}
