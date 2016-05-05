/*
** File: midrockway.c
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
    set("short", "Climbing the rocks");
    set( "long", @EndText
You're half way from climbing the rocks. Some of them
are covered with green limo and are slippery. Others
are wet from the drops of the cascade. Right now
you have three ways to go on; The cave behind the
cascade, up to reach the top of the cascade, or
down to go back the way you came.
EndText);
    set( "exits", ([
      "cave" : ARV_ROOM+"cave.c",
      "up" : ARV_ROOM+"topcascade.c",
      "down" : ARV_ROOM+"cascade.c",
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
