#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set ("author", "cyanide");
    set ("arena" ,1);
    set ("light", 0);
    set ("short", "A Grand Volcano View");
    set( "long", @EndText
You are on a ledge in the middle of a large volcano. Below you the volcano
bottom can be seen and above is the rim of the volcano. A couple of ledges
can be seen on the other side of the volcano. The exit from the ledge
is to the south, and a crack in the western wall leads into blackness.
EndText
    );
    set( "exits", ([
      "west" : MAIN+"/crack.c",
      "south" : MAIN+"/lava2.c",
    ]) );

    set ("item_desc", ([
      "crack" : "You can feel a cool breeze coming from it.\n",
    ]) );
}
