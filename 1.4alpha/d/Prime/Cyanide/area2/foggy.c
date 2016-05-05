#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    set("author", "cyanide");
    set ("short", "Foggy Room");
    set( "long", @EndText
You are in a dank passage filled with a wispy fog. A spooky passageway
leads north and a wider path heads off to the southwest. To the west,
the passageway leaves the rock and enters an eerie, shadowy land; and
to the south, a narrow path leads to a small stream.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/creepy.c",
      "west" : MAIN+"/LOS01.c",
      "southwest" : MAIN+"/lakeshore.c",
      "south" : MAIN+"/nearstream.c"
    ]) );

    set ("item_desc", ([
      "fog" : "Now how do you propose to do that?\n",
    ]) );
}
