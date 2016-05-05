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
	"The tunnel continues down, growing narrower with each "+
	"step. The silence grows deafening. ",
      ) );
    set( "exits", ([
      "southeast" : "/u/s/sophia/pad8.c",
      "northwest" : "/u/s/sophia/pad11.c",
    ]) );
    set("item_desc", ([
"floor" : "solid bedrock now..cold and damp \n",
      "walls" : "More dirt. There is a small clump hanging from a root.\n",
      "clump" : "A funny looking ball of earth. \n",
      "torch" : "An ordinary looking torch; perhaps you could light it.\n",
    ]) );
}
