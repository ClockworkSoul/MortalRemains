
/* This is Room 19 in Tyran's Spider Caves
AKA, the Widow of the Web's Lair
Re-coded on 7/6/2000*/

#include <mudlib.h>
#include <config.h>
#include "spider.h"

inherit ROOM;

void create ()
{

        object widow;

        ::create();
        seteuid( geteuid() );
        set( "author", "tyran");
        set( "light", 1 );
        set( "short", "The Widow's Lair" );
        set( "long", @EndText
   This room is one giant mass of webs.  The webs
cover the walls, floor and ceiling.  The webbing
covers everything and is very sticky to the touch.
Careful, or you might get stuck!
EndText
        );
 set("pre_exit_func", ([
        "west" : "widow_check",  
    ]) );
set( "exits", ([
"west" : SPD_ROOM+"spcave20.c",
"east" : SPD_ROOM+"spcave18.c",
        ]) );

    reset();
    widow = clone_object(SPD_MON+"widow.c");
    widow->move(TO);
set("item_desc", ([
    "walls" : "The walls are so covered in webs you can't see them.\n",
    "wall" : "The walls are so covered in webs you can't see them.\n",
    "ceiling" : "The web obscures your view of the ceiling.\n",
    "web" : "This webbing covers everything.  It is made of a white sticky material.\n",
    "floor" : "The floor is covered in the webbing.\n"
    ]));
}

int widow_check()
{
    if (present("widow", TO))
        {
        write("The Widow of the Web hisses at you as you try to enter\n"+
              "the room to the west.  Wonder what's in there?\n");
        return 1;
        }
    return 0;
}