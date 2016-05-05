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
You are on the main road in Hill Vally, You can see the Town
Square further north, Houses line the east and west of road.
The entrance to Hill Vally is south.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm3.c",
     "north" : RM+"rm5.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
     "road" : "Quite dusty.\n",
     "town square" : "Further north.\n",
     "houses" : "There are a few on the west and east of the road.\n",
    ]) );
}
