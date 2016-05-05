#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep14.c",
      "west" : DEEP+"deep16.c",
    ]) );
    set("objects" , ([
      "shark" : O_MON+"shark.c",
      "catfish" : O_MON+"cat.c",
    ]) );
    reset();
}
