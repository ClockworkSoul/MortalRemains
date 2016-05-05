/*
** File: gate.c
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
    set("short", "Village Town");
    set( "long", @EndText
This is the end of the Village Town. in front of you is the
gate that will lead you out of the village. A little further
from the gate, you can see a dense forest. A breeze caresses
your face... a cold one. Your body senses the presence of
a waterfall, and you can hear it's enchanting sound closer.
EndText);
    set( "exits", ([
      "south" : ARV_ROOM+"pathway.c",
      "north" : ARV_ROOM+"forest1.c",
    ]) );
    set("item_desc", ([
      "gate" : "An iron gate that protects the castle lands from foreigners.\n",
      "forest" : "Not from here. But you can see some pine trees.\n",
      "waterfall" : "You're quite far from seeing the cascade yet.\n",
    ]) );
    set("listen", wrap(
	"You hear the fresh sound of waterfalls, which has entranced\n"+
	"you to the point of leaving the tower. You're obsessed\n"+
	"with it...\n"));
}

/* EOF */
