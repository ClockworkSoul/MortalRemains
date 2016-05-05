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
    set("objects",(["mage" : "/d/Prime/Magehouse/monsters/mage5.c"]) );
    reset();
    set( "short", "House of the Mage");
    set( "long",@EndText
Utter blackness is your only company in this room. Black stone walls, 
black floor and ceiling, and black eyes, hovering directly before you.
They say to you, "Welcome to your doom! Oh wait, wrong mortal. Be gone,
you. I do not have time for one as small as yourself! Come back later when
your strongest blow could even get past my first shield."
EndText
);
    set( "exits", ([
"west" : N_ROOM+"room8.c",
    ]) );
    set( "item_desc", ([
        "eyes" : "They are standing before you, waiting for you to leave.\n",
        "floor" : "It is black and utterly featureless.\n",
        "ceiling" : "It is black and utterly featureless.\n",
        "walls" : "They are black and utterly featureless.\n",
    ]) );
}

/* EOF */
