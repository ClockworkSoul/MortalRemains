inherit ROOM;

#include "sophia.h"
void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "author", "sophia");
    set("short", "an earthen tunnel" );
    set("long", wrap(
	"A tunnel dug through the earth going somewhere unknown. "
      ) );
    set( "exits", ([
"south" : "/u/s/sophia/pad7.c",
"north" : "/u/s/sophia/pad8.c",
    ]) );
    set("item_desc", ([
      "floor" : "nothing but a dirt packed path. \n",
      "walls" : "dirt all the way up, just dirt. \n",
    ]) );
}
