/*
** File: cave2.c
** Author: Lady Nsd
** Other comments: To secure peace is to prepare for war!!
*/

#include <config.h>
#include <mudlib.h>
#include "arv.h"

inherit ROOM;

void create() {
    ::create();
    seteuid( getuid() );
    set( "light", 0 );
    set("author", "nsd");
    set("short", "Inside the cave");
    set( "long", @EndText
You're deeper inside the cave. The sound of the waterfalls
echoes in here, producing an enchanting song. For some
reason you hear a female singing voice that echoes really
low and distant, and dies away...  You wonder where that
voice comes from.
EndText);
    set( "exits", ([
      "south" : ARV_ROOM+"cave.c",
      "north" : ARV_ROOM+"cave3.c",
    ]) );
    set("item_desc", ([
    ]) );
    set("listen", wrap(
      ));
}
void init () {
    add_action("?", "?");
}

/* EOF */
