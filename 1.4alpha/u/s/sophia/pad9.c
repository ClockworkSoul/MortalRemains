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
	"You come to an abrupt stop. There tunnels stops at a  "+
	"large door with a large iron lock. There is a torch "+
	"on the wall here. "
      ) );
    set( "exits", ([
      "west" : "u/s/sophia/pad8.c"
    ]) );
    set("item_desc", ([
      "floor" : "nothing but a dirt packed path. \n",
      "walls" : "dirt all the way up, just dirt. \n",
      "torch" : "An ordinary looking torch; perhaps you could light it.\n",
    ]) );
}
