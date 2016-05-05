/*
** File: topcascade.c
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
    set("short", "Top of the cascade");
    set( "long", @EndText
You have reached the top of the cascade.
Here the river runs furiously and strongly.
The down view from here is enchanting. You
can fill your lungs with fresh air.
Certainly this part of the river makes you
feel really romantic...
EndText
    );
    set( "exits", ([
      "down" : ARV_ROOM+"midrockway.c",
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
