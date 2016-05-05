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
You are walking along Crest Road in Hill Vally. In the distance to the
south you can vaguely make out the town square. Just ahead north are
the town walls. A smaller side road branches off to the west.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm8.c",
     "north" : RM+"rm10.c",
     "west" : RM+"SL1.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "square" : "To the south, you can barely make it out.\n",
     "road" : "A smaller road leading west.\n",
     "walls" : "They house the town, just to the north.\n",
     "town square" : "To the south, You can barely make it out.\n",
    ]) );
}
