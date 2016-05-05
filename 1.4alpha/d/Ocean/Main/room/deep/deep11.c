#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep10.c",
      "west" : DEEP+"deep12.c",
    ]) );
    set("objects" , ([
      "ganderewa" : O_MON+"ganderewa.c",
      "leaper" : O_MON+"leaper.c",
    ]) );
    reset();
}
