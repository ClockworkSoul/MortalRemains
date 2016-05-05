#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Abbey Road");
    set( "long", @EndText
You stand before what looks like a once beautiful Abbey to a lost
Deity. The walls are made of ivory, but now dirtied by the rains and
wrath of time. The old, rusty, adamantite gate hangs by a hinge, and
bids you entrance. A smaller dirt path leads around back to what looks
like a graveyard.
EndText
    );
    set( "exits", ([
     "east" : RM+"abbey1.c",
     "southeast" : RM+"grave1.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "gate" : "What was once a masterpiece now hangs by a hinge.\n",
     "path" : "Leading around back.\n",
     "walls" : "Weathered and beaten by father time.\n",
     "abbey" : "Your standing before the entrance.\n",
    ]) );
}
