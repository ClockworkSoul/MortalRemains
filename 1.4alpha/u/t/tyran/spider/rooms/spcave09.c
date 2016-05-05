/* This is Room 9 in Tyran's Spider Caves
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
   The ceiling and floor is made of a grey stone, 
and seem to be some what smooth.  The ceiling
is of a respectible height.  There are spider
webs everywhere
EndText
        );

set( "exits", ([
"west" : SPD_ROOM+"spcave08.c",
"north" : SPD_ROOM+"spcave11.c",
"northeast" : SPD_ROOM+"spcave12.c",
"east" : SPD_ROOM+"spcave10.c",
"southeast" : SPD_ROOM+"spcave07.c",
"south" : SPD_ROOM+"spcave06.c",
"southwest" : SPD_ROOM+"spcave05.c",
        ]) );

    reset();
    gtspidey = clone_object(SPD_MON+"gtspidey.c");
    gtspidey->move(TO);
set("item_desc", ([
    "ceiling" : "The ceiling is made of smooth grey rock.\n",
    "floor" : "The floor is made of smooth grey rock.  A couple webs are anchored.\n",
    "webs" : "Run of the mill spiderwebs.... only a lot bigger.",
    ]));

}