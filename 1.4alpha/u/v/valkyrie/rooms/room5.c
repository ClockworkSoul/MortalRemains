#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author", "blood");
    set( "short", "House of the Mage");
    set( "long",@EndText
Your feet get soaked from the water on the ground, in this room. In fact,
as you look around, you have to blink a bit as your eyes can't believe
what your mind is telling them. Rainbows of every size float in the air.
How they are here, you have no idea, because no visible light can be seen.
EndText
);
    set( "exits", ([
        "east" : N_ROOM+"room4.c",
         "rainbows" : "/d/Prime/Magehouse/maze/maze1.c",
    ]) );
    set( "item_desc", ([
    "water" : "It seems fresh, and is about ankle-deep.\n",
    "rainbows" : "They are everywhere, simple hovering in mid air.\n",
    ]) );
    set("search_desc", ([
    "rainbows" : "They dissapear as you move close.\n",
    ]) );
}

/* EOF */
