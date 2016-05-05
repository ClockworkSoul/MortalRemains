#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    set("author", "cyanide");
    set ("short", "Path Near Stream");
    set( "long", @EndText
The path follows the south edge of a deep ravine and leads
northwest, narrowing to a rather tight crawl. On the east is
a ruined archway.
EndText
    );
    set( "exits", ([
      "enter" : MAIN+"/sanctuary.c",
      "northeast" : MAIN+"/darktunn.c",
      "east" : MAIN+"/cgarden.c",
      "northwest" : MAIN+"/foggy.c"
    ]) );
    set ("exit_suppress", ({"enter"}) );

    set ("item_desc", ([
      "path" : "It follows the southern edge of a very deep ravine, and leads\n"+
      "from the east to the northwest.\n",
      "archway" : "Well, it's ruined... Can't you read?\n",
      "ravine" : "It is very deep, and you can't see the bottom. There seems\n"+
      "to be no way to cross it. To enter it would be suicide.\n",
    ]) );
}
