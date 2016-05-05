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
This room gives you a feeling of warmth as you enter it. Couches, beds,
tables and chairs fill this huge room in a style that can only be described
as 'eclectic'. An ornate fireplace with a large and incredibly hot fire 
blazing in it. Along the eastern wall is another one of those blasted 
mirrors. You wonder if this mage was cute, or just very vain?
EndText
);
    set( "exits", ([
"west" : N_ROOM+"room2.c",
"north" : N_ROOM+"room4.c",
    ]) );
    set( "item_desc", ([
        "mirror" : "A very ugly person stares back at you.\n",
        "person" : "Hey!  You're that ugly person!\n",
        "couches" : "Several of the fill the room, in a variety of styles.\n",
        "beds" : "You wonder who in the world needs more than one bed?\n",
        "tables" : "They are mostly covered with momentos and knick-knacks.\n",
        "momentos" : "Mostly boring tuff like matchbooks and porcelin cats.\n",
        "knick-knacks" : "Mostly boring tuff like matchbooks and porcelin cats.\n",
        "chairs" : "Lots of comfy, high-backed chairs.\n",
        "cats" : "Hundreds of them...   this guy seems a tad eccentric.\n",
        "matchbooks" : "Mostly from bed and breakfasts around the world.\n",
    ]) );
}

/* EOF */