#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    seteuid( getuid() );
    set("author" , "herself");
    set("underwater" , 1);
    set( "exits", ([
      "east" : DEEP+"deep16.c",
      "south" : DEEP+"deep18.c",
    ]) );
    set("objects" , ([
      "whale" : O_MON+"whale.c",
      "eel" : O_MON+"eel.c",
    ]) );
    reset();
}
