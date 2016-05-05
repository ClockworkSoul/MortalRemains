/*
* Desc: part of the sea.
*/

#include <mudlib.h>
#include "ocean.h"

inherit ROOM;

void init()
{
}

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("smell" , "The salty smell of sea water greets you. \n");
    set("short" , "The Sea");
    set( "long", wrap( 
	"You are bobbing around in the water. "+
	"The sun beats down on your head. "+
	"The sea seems to stretch for miles here. "
      ));

    set("objects" , ([
      "octopus" : O_MON+"octopus.c",
      "manatee" : O_MON+"manatee.c",
      "fish" : O_MON+"fish.c",
    ]) );
    reset();
    set("item_desc", ([
      "ocean#sea" : "Water is all around you, for miles. \n",
      "sun#hot sun" : "You squint up at the sun, but it hurts your eyes. \n",
      "water" : "You can see your reflection, a bit distorted. \n",
      "reflection" : "It looks like you, except a bit twisted. \n",
    ]));

    set( "exits", ([
      "east" : O_ROOM+"sea8.c",
      "north" : O_ROOM+"sea4.c",
    ]) );
}
