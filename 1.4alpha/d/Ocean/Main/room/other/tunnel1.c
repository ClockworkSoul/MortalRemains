/*
* FILE: tunnel1.c
* DESC: beginning of a tunnel
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
    //add_action("subroutine", "command");
}

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("smell" , "It smells like wildflowers. \n");
    set("author" , "herself");
    set("short" , "A Glass Path");
    set( "long", wrap( 
	"You are standing on a glass path. The water seems to "+
	"have parted here. An unexplainable force holds the "+
	"water away from the path, preventing it from "+
	"crushing in on you. Beautiful wildlife has overtaken this area. "+
	"exotic flowers and other foliage please the eye. "+
	"Some kind of incredible ivy climbs up the "+
	"walls made out of water. "
      ));

    set("item_desc", ([
      "wall#walls" : "The walls are made out of water. \n",
      "water" : "Some unexplainable force holds the water away. \n",
      "path" : "The path is made out of clear glass. \n",
      "glass" : "It is completely smooth. \n",
    ]));

    set( "exits", ([
      "crack" : O_ROOM+"sea_cave.c",
      "east"  : O_ROOM+"tunnel2.c",
    ]));
}

