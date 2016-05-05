#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("objects",(["mage" : "/d/Prime/Magehouse/monsters/mage3.c"]) );
    reset();
    set("author", "blood");
    set( "short", "House of the Mage");
    set( "long",@EndText
As you enter the room, you are blinded by the brilliant light in here.
Bright balls of light fly around this room, reflecting off the millions
and millions of polished silver scrolls that are stored in niches in the
wall. This must have been the mage's library. Only one with powers to 
shield the mind and body from the defenses of the scrolls could even touch
them, much less read them.
EndText
);
    set( "exits", ([
"west" : N_ROOM+"room2.c",
"south" : N_ROOM+"room7.c",
    ]) );
    set( "item_desc", ([
    "scrolls" : "As you appreach them, you get a slight shock.\nTo go "+
        "any closer would be unwise.\n",
    "balls" : "Magical spheres of light, hovering in the air.\n",
    "niches" : "Little holes carved into the stone walls.\n",
    ]) );
}

/* EOF */
