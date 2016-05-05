/*
** File: seelietower.c
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
    set("short", "Inside the tower");
    set( "long", @EndText
You are inside the giant oak tree, which is more than a simple tree.
It's been fixed to be a seelie tower. On the walls, you see some
tapestries crafted of the finest materials. A stairway leads up,
and a Hunter-Green carpet leads north to another chamber.
EndText );
    set( "exits", ([
      "out" : ARV_ROOM+"seeliecourt3.c",
      "up" : ARV_ROOM+"seelietower2.c",
      "north" : ARV_ROOM+"courtyard.c",
    ]) );
    set("item_desc", ([
      "tapestries" :
      "Fine tapestries made of unknown materials. They have strange\n"+
      "symbols embroidered of golden threads.\n",
      "symbols" : "Nothing other than a reflection of the seelie court life.\n",
      "carpet" : "A dark green carpet that leads north to another chamber.\n",
      "walls" : "Just the inner part of the oak tree. They have tapestries.\n",
    ]) );
}

/* EOF */
