#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "north" : DEEP+"deep20.c",
      "south" : DEEP+"deep22.c",
    ]) );
    set("objects" , ([
      "whale" : O_MON+"whale.c",
      "anemone" : O_MON+"anemone.c",
      "jellyfish" : O_MON+"jfish.c",
      "eel" : O_MON+"eel.c",
    ]) );
    reset();
}
