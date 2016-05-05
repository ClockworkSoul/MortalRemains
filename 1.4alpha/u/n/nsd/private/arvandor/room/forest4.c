/*
** File: forest4.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "nsd");
    set("short", "Dense Forest");
    set( "long", @EndText
You're in a dense forest. Only few strands of sunlight
find their way between the branches of the pine trees.
Your senses tell you that the river must be closer if
you keep going east.
EndText);
    set( "exits", ([
      "west" : ARV_ROOM+"forest3.c",
      "east" : ARV_ROOM+"forest5.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
    ]) );
    set("listen", wrap(
	"You hear the wind swirling and moving some dry leaves.\n"+
	"And the sound of the waterfalls haven't ceased...\n"));
}

/* EOF */
