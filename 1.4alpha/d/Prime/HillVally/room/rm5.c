#include <config.h>
#include <mudlib.h>

inherit ROOM;

#include "../camel.h"

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
   set("short", "Town Square");
    set( "long", @EndText
You are standing in the Town Square. This is one of the more lively
parts of Hill Vally. To the west is Chestnut street, while east lies
Peanut Street. Crest Road continues further on to the north. There is
a rather large fountain in the center of the square. You also notice
a small shop to the east, there is a sign hanging above it.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm4.c",
     "north" : RM+"rm6.c",
     "west" : RM+"Cstreet1.c",
     "east" : RM+"Pstreet1.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
