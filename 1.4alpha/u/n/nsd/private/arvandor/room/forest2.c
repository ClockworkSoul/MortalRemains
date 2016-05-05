/*
** File: forest2.c
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
You're in a dense forest. Only few strands of sunlight
find their way between the branches of the pine trees.
Your senses tell you that the river must be closer if
you keep going northeast.
EndText
    );
    set( "exits", ([
      "south" : ARV_ROOM+"forest1.c",
      "northeast" : ARV_ROOM+"forest3.c",
      "north" : ARV_ROOM+"gobvillage.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
    ]) );
    set("listen", wrap(
	"The song of the cascade has made you lose your will.\n"+
	"You think of nothing else but the river...\n"));
}

/* EOF */
