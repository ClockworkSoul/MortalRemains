#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep2.c", 
      "east" : DEEP+"deep4.c",
    ]) );
    set("objects" , ([
      "eel" : O_MON+"eel.c",
      "leaper" : O_MON+"leaper.c",
    ]) );
    reset();
}
