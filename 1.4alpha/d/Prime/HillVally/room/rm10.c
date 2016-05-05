#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Crest Road");
    set( "long", @EndText
You have come to the end of Crest Road. The town walls halt your
passage to the north. The only way back is south. A small road leads
east to the town's Abbey.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm9.c",
     "east" : RM+"AR1.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "abbey" : "You can hardly see it from here.\n",
     "walls" : "They are weatherbeaten and cracked.\n",
     "cracks" : "Nothing special, just plain cracks.\n",
     "road" : "It branches to the east.\n",
    ]) );
}
