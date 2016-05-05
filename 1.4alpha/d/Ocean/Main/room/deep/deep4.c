#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "north" : DEEP+"deep5.c",
      "west" : DEEP+"deep3.c",
    ]) );
    set("objects" , ([
      "anemone" : O_MON+"anemone.c",
      "eel" : O_MON+"eleceel.c",
    ]) );
    reset();
}
