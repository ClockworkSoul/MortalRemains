/*
** File: forest1.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create(){
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Dense Forest");
    set( "long", @EndText
You're past the gate, outside the lands of the village.
After the gate, you wonder around at your own risk.
You're in a dense forest. Only few strands of sunlight
find their way between the branches of the pine trees.
Your senses tell you that the river must be closer if
you keep going north.
To the south is the gate that leads you back to the
village.
EndText);
    set( "exits", ([
      "south" : ARV_ROOM+"gate.c",
      "north" : ARV_ROOM+"forest2.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
      "gate" : "An iron gate that leads you back to village.\n",
    ]) );
    set("listen", wrap(
	"You hear the fresh sound of waterfalls, which has entranced\n"+
	"you to the point of leaving the tower. You're more than\n"+
	"entranced, you're in love...\n"));
}

/* EOF */
