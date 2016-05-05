/* This is Room 3 in Tyran's Spider Caves
Coded on 7/19/2000*/

#include <mudlib.h>
#include <config.h>
#include "spider.h"

inherit ROOM;

void create ()
{

        object smspidey;

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
"southwest" : SPD_ROOM+"spcave01.c",
"west" : SPD_ROOM+"spcave02.c",
"northwest" : SPD_ROOM+"spcave05.c",
"north" : SPD_ROOM+"spcave06.c",
"northeast" : SPD_ROOM+"spcave07.c",
        ]) );

    reset();
    smspidey = clone_object(SPD_MON+"smspidey.c");
    smspidey->move(TO);
set("item_desc", ([
    "ceiling" : "The ceiling is made of smooth grey rock.\n",
    "walls" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "wall" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "floor" : "The floor is made of smooth grey rock.  A couple webs are anchored.\n",
    "deposits" : "These deposits appear to be made of some form of chalk.\n",
    "webs" : "Run of the mill spiderwebs.... only a lot bigger.",
    "chalk" : "This chalky substance rubs off the wall onto your hand.\n"+
    "You wonder what caused it.\n",
    ]));

}