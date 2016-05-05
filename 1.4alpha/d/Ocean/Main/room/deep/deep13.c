#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep12.c",
      "west" : DEEP+"deep14.c",
    ]) );

}
