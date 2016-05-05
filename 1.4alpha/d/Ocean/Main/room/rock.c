/*
* Desc: A rock, in the ocean.
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
    set("listen" , "You hear the sound of water lapping.\n");
    set("author" , "herself");
    set("short" , "atop a large rock");
    set( "long", wrap( 
	"You are standing on a large rock, in the middle "+
	"of the ocean. The water splashes against the "+
	"bottom of the rock. Your face feels warm in the "+
	"hot sun. "
      ));

    set("objects" , ([
      "turtle" : O_MON+"turtle.c",
      "siren" : O_MON+"siren.c",
    ]) );
    reset();
    set("item_desc", ([
      "rock#large rock" : "You are standing on it. \n",
      "ocean#sea" : "Water is all around you, for miles. \n",
      "sun#hot sun" : "You squint up at the sun, but it hurts your eyes. \n",
      "water" : "You can see your reflection, a bit distorted. \n",
      "reflection" : "It looks like you, except a bit twisted. \n",
    ]));

    set( "exits", ([
      "down" : O_ROOM+"sea.c",
    ]) );
}
