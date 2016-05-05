
/* This is the entrance to Tyran's Spider Caves
Re-coded on 7/6/2000*/

#include <mudlib.h>
#include <config.h>
#include "spider.h"

inherit ROOM;

void create ()
{
        ::create();
        seteuid( geteuid() );
        set( "author", "tyran");
        set( "light", 1 );
        set( "short", "Entrance to the Caves" );
        set( "long", @EndText
   You are in the entrance to some small caves.
The walls of the caves are laced with white
chalky looking deposits.  The ceiling is of a
moderate height, and the walls and ceiling here
seem to be somewhat smooth.
EndText
        );

set( "exits", ([
"north" : SPD_ROOM+"spcave02.c",
"northeast" : SPD_ROOM+"spcave03.c"
        ]) );
set("item_desc", ([
    "ceiling" : "The ceiling is made of smooth grey rock.\n",
    "deposits" : "These deposits appear to be made of some form of chalk.\n",
    "walls" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "wall" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "floor" : "The floor is made of smooth grey rock.  A couple webs are anchored.\n",
    "chalk" : "This chalky substance rubs off the wall onto your hand.\n"+
    "You wonder what caused it.\n",
    ]));
}