
/* This is Room 8 in Tyran's Spider Caves
Coded on 7/19/2000*/

#include <mudlib.h>
#include <config.h>
#include "spider.h"

inherit ROOM;

void create ()
{

        object gtspidey;

        ::create();
        seteuid( geteuid() );
        set( "author", "tyran");
        set( "light", 1 );
        set( "short", "Inside the caves" );
        set( "long", @EndText
   The walls of the caves are laced with white
chalky looking deposits.  The ceiling is of a
moderate height, and the walls and ceiling here
seem to be somewhat smooth.  There are spider
webs everywhere
EndText
        );

set( "exits", ([
"northeast" : SPD_ROOM+"spcave11.c",
"east" : SPD_ROOM+"spcave09.c",
"southeast" : SPD_ROOM+"spcave06.c",
"south" : SPD_ROOM+"spcave05.c",
"southwest" : SPD_ROOM+"spcave04.c",
        ]) );

    reset();
    gtspidey = clone_object(SPD_MON+"gtspidey.c");
    gtspidey->move(TO);
set("item_desc", ([
    "ceiling" : "The ceiling is made of smooth grey rock.\n",
    "deposits" : "These deposits appear to be made of some form of chalk.\n",
    "walls" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "wall" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "floor" : "The floor is made of smooth grey rock.  A couple webs are anchored.\n",
    "webs" : "Run of the mill spiderwebs.... only a lot bigger.\n",
    "chalk" : "This chalky substance rubs off the wall onto your hand.\n"+
    "You wonder what caused it.\n",
    ]));

}