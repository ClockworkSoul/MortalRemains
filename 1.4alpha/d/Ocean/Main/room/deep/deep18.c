#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "north" : DEEP+"deep17.c",
      "south" : DEEP+"deep19.c",
      "east" : DEEP+"uroom.c",
    ]) );

}
