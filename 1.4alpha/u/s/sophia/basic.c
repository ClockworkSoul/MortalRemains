inherit ROOM;

#include "sophia.h"
void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set( "short", "A post apocolyptic desert" );
set("long", wrap(
"you "+
"posted. "
) );
    set( "exits", ([
"north" : "SOPHIA+ "herbgarden.c",
    ]) );
    set("item_desc", ([
      "sand" : "hot and black.\n",
    ]) );
}
