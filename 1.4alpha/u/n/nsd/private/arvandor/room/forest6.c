/*
** File: forest6.c
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
      "northwest" : ARV_ROOM+"forest5.c",
      "east" : ARV_ROOM+"forest7.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
    ]) );
    set("listen", wrap(
	"The wind sounds furiously now, almost like a storm.\n"+
	"The cascade seems to mute for a moment...\n"));
}

/* EOF */
