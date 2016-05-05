#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", " -{ CYANIDE }- ");
    set ("arena" ,1);
    set ("light", 0);
    set ("area_type", ([
      "blue" : 1,
      "black" : 2,
    ]) );
    set ("short", "Cool Room");
    set( "long", @EndText
The room is cool and damp. The air is misty. A twisty path from the
southeast splits here toward a wide northerly stone bridge, and a narrow
westerly tunnel. It is from the latter that the mist and chill seem to
originate.
EndText
    );
    set( "exits", ([
      "east" : MAIN+"/mirror1.c",
      "southeast" : MAIN+"/junction.c",
      "west" : MAIN+"/ice.c",
    ]) );

    set ("item_desc", ([
    ]) );
}
