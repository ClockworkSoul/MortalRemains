#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "east" : DEEP+"deep13.c",
      "west" : DEEP+"deep15.c",
    ]) );
    set("objects" , ([
      "jellyfish" : O_MON+"jfish.c",
      "eel" : O_MON+"eel.c",
      "anemone" : O_MON+"anemone.c",
    ]) );
    reset();

}
