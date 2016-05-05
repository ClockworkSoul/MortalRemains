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
Yuo are on the main road in Hill Vally called Crest road.
To the south, You see the entrance to this fine town. To the
west lies a small house, a street branches off to the east, while
Crest Road continues on north to the Town Square.
EndText
    );
    set( "exits", ([
   "south" : RM+"rm1.c",
   "north" : RM+"rm3.c",
   "west" : RM+"gatehouse.c",
   "east" : RM+"Wstreet1.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "road" : "Your walking on it genius, what'd ya expect to see?\n",
     "house" : "It looks like a gatehouse of some sort.\n",
     "street" : "It forks to the east, Yuo see homes lining the street.\n",
     "town" : "Now your in it, much better than just seeing it, eh?\n",
     "entrance" : "Mabye we should call it the exit now?\n",
    ]) );
}
