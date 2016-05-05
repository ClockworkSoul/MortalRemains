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

    set("item_desc", ([
      "ocean#sea" : "Water is all around you, for miles. \n",
      "sun#hot sun" : "You squint up at the sun, but it hurts your eyes. \n",
      "water" : "You can see your reflection, a bit distorted. \n",
      "reflection" : "It looks like you, except a bit twisted. \n",
    ]));

    set( "exits", ([
      "south" : O_ROOM+"sea1.c",
      "east" : O_ROOM+"sea11.c",
      "west" : O_ROOM+"sea13.c",
      "north" : O_ROOM+"sea17.c",
    ]) );
}
void reset() {
    object ob;
    if (!present("seahorse")) {
	ob = clone_object(O_MON+"seahorse.c");
	ob->move(TO);
	ob = clone_object(O_MON+"seahorse.c");
	ob->move(TO);
    }
    if (!present("piranha", TO)) {
	ob = clone_object(O_MON+"piranha.c");
	ob->move(TO);
    }
}
