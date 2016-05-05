/*
** File: forest5.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!!!
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
you keep going southeast.
EndText
    );
    set( "exits", ([
      "west" : ARV_ROOM+"forest4.c",
      "southeast" : ARV_ROOM+"forest6.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
    ]) );
    set("listen", wrap(
	"The wind passing through the few spaces left by the\n"+
	"dense forest produces a whistling sound.\n"+
	"The waterfalls and the wind, together, make\n"+
	"a sweet melody...\n"));
}

/* EOF */
