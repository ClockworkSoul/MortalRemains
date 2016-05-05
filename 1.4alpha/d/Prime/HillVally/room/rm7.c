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
You are walking along the main road in Hill Vally. To the north the
town continues, the road leads back south to the town square. Houses
line the road to the east, while a smaller side road runs west.
EndText
    );
    set( "exits", ([
     "west" : RM+"COstreet1.c",
     "south" : RM+"rm6.c",
     "north" : RM+"rm8.c",
    ]) );
    set("item_desc", ([
     "town" : "You're in it.\n",
     "houses" : "They line the east side of the road.\n",
     "square" : "That's to the south.\n",
   "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
