/*
** File: riverway.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!!
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
This part of the forest has a strange attraction.
Every person that discovers it, wants to come back
always. A rainbow filters from within the branches
revealing a giant prism of enchanting color. It's
the clear hint of water, so the cascade must be
close now.
EndText);
    set( "exits", ([
      "out" : ARV_ROOM+"forest7.c",
      "south" : ARV_ROOM+"riverway2.c",
    ]) );
    set("item_desc", ([
      "trees" : "Broad pine trees full of branches.\n",
      "rainbow" : wrap(
	"Strands of sunlight that make contact with dew,\n"+
	"making a wonderfull bow of transparent color. A rainbow\n"+
	"is nothing else than the clear sign of water. Keep on\n"+
	"wondering around, and you'll find the cascade..."),
    ]) );
    set("objects", ([
      "butterfly" : ARV_MON+"butterfly.c",
    ]) );
    reset ();
    set("listen", wrap(
	"You hear wind chimes as a far sound... The cascade\n"+
	"keeps transmiting it's entrancing song, which has\n"+
	"made you come this far...\n"));
}

/* EOF */
