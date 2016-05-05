#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep15.c",
      "west" : DEEP+"deep17.c",
      "north" : DEEP+"levroom.c",
    ]) );

}
