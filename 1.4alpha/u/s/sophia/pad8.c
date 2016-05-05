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
	"The tunnel splits here, turning sharply to the east in "+
	"one direction and sloping steeply downwards to the northwest.",
      ) );
    set( "exits", ([
      "east" : "/u/s/sophia/pad9.c",
      "northwest" : "/u/s/sophia/pad10.c",
      "south" : "/u/s/sophia/pad7.c",
    ]) );
    set("item_desc", ([
      "floor" : "nothing but a dirt packed path. \n",
      "walls" : "dirt all the way up, just dirt. \n",
      "torch" : "An ordinary looking torch; perhaps you could light it.\n",
    ]) );
}
