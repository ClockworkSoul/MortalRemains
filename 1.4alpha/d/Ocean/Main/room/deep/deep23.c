#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep22.c",
      "east" : DEEP+"deep24.c",
    ]) );
    set("objects" , ([
      "swordfish" : O_MON+"swordfish.c",
      "eel" : O_MON+"eleceel.c",
      "stingray" : O_MON+"stingray.c",
    ]) );
    reset();
}
