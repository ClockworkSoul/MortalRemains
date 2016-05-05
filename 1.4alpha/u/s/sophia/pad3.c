inherit ROOM;

#include "sophia.h"
void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
set("short", "A train car" );
set( "long", wrap(
"As you step into the first of two cars the pullman punches "+
"your ticket. Others on the train look like they would punch your "+
"ticket as well if they had the chance. You sit down on what "+
"is left of a seat and pray this train can stay on the rails."
) );
    set( "exits", ([
      "north" : "/u/s/sophia/herbgarden.c",
    ]) );
    set("item_desc", ([
      "sand" : "hot and black.\n",
    ]) );
}
