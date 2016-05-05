/*
** File: cave.c
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
    set( "light", 0 );
    set("author", "nsd");
    set("short", "Inside the cave");
    set( "long", @EndText
This is a warm and private corner inside the
cascade. Not many living beings know of this
cave. This is the perfect room for secret
meetings of any kind. From here, the waterfalls
look like a crystal clear curtain, distorting
the outside view to abstract forms full of color.
EndText);
    set( "exits", ([
      "out" : ARV_ROOM+"midrockway.c",
      "north" : ARV_ROOM+"cave2.c",
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
