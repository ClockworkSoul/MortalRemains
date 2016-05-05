#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "north" : DEEP+"deep19.c",
      "south" : DEEP+"deep21.c",
    ]) );
    set("objects" , ([
      "eel" : O_MON+"eleceel.c",
      "stingray" : O_MON+"stingray.c",
    ]) );
    reset();
}
