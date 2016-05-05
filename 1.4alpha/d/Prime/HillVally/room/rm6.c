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
You are walking along the main road in Hill Vally, to the north you
see more of the town, the Square is to the south, to your east and
west houses line the road.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm5.c",
     "north" : RM+"rm7.c",
    ]) );
    set("item_desc", ([
     "town" : "You're in it.\n",
     "square" : "That's to the south.\n",
     "houses" : "They line the road.\n",
     "road" : "Under you, there it is again!\n",
   "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
