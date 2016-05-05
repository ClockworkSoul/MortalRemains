#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "south" : DEEP+"deep8.c",
      "west" : DEEP+"deep10.c",
    ]) );
    set("objects" , ([
      "stingray" : O_MON+"stingray.c",
      "catfish" : O_MON+"cat.c",
    ]));
    reset();
}
