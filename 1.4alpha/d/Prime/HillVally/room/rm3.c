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
You are walking along the main road in Hill Vally. To the north you
see what looks like the Twon Square, A small bake shop is to the 
west.
EndText
    );
    set( "exits", ([
     "south" : RM+"rm2.c",
     "north" : RM+"rm4.c",
     "west" : RM+"bakeshop.c",
    ]) );
    set("item_desc", ([
   "path" : "Right there under you feet, what did you expect?\n",
    ]) );
}
