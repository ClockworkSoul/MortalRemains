#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    set("author", "cyanide");
    set ("light", 1);
    set ("short", "Shallow Ford");
    set( "long", @EndText
You are at the southern end of a great cavern. To the south
across a shallow ford is a dark tunnel which looks like it was
once enlarged and smoothed. To the north a path stalagmites. Dim
light illuminates the cavern.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/gr8cav.c",
      "south" : MAIN+"/darktunn.c",
    ]) );
    set ("exit_suppress", ({"enter"}) );
    set ("item_desc", ([
      "moss" : "It is glowing with a soft yellow-green light.\n",
    ]) );
}
