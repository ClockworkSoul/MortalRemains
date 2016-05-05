/*
** File: seeliecourt3.c
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
    set("short", "Pathway to Seelie Court");
    set( "long", @EndText
Here the path ends. You're before a giant oak tree that looks
really weird, and blocks the way. All around you seem abnormally
big.
EndText );
    set( "exits", ([
      "west" : ARV_ROOM+"seeliecourt2a.c",
      "enter" : ARV_ROOM+"seelietower.c",
    ]) );
    set("item_desc", ([
      "tree" : "What tree do you wish to see?\n",
      "oak tree" : "Looks like you can inhabit it. There's a hole in it.\n",
      "hole" : "This is the normal entrance. What the hell, just 'enter'.\n",
    ]) );
}

/* EOF */
