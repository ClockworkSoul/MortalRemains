#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "south" : DEEP+"deep5.c",
      "north" : DEEP+"deep7.c",
    ]) );
    set("objects" , ([
      "ganderewa" : O_MON+"ganderewa.c",
    ]) );
    reset();
}
