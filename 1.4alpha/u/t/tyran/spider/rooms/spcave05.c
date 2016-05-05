/* This is Room 5 in Tyran's Spider Caves
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
   The ceiling is of amoderate height, and 
both the floor and the ceiling seem to be somewhat 
smooth.  There are spider webs everywhere
EndText
        );

set( "exits", ([
"west" : SPD_ROOM+"spcave04.c",
"north" : SPD_ROOM+"spcave08.c",
"northeast" : SPD_ROOM+"spcave09.c",
"east" : SPD_ROOM+"spcave06.c",
"southeast" : SPD_ROOM+"spcave03.c",
"south" : SPD_ROOM+"spcave02.c",
        ]) );

    reset();
    smspidey = clone_object(SPD_MON+"smspidey.c");
    smspidey->move(TO);
set("item_desc", ([
    "ceiling" : "The ceiling is made of smooth grey rock.\n",
    "walls" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "wall" : "The walls are made of smooth grey rock.  There's some chalky stuff on them.\n",
    "floor" : "The floor is made of smooth grey rock.  A couple webs are anchored.\n",
    "webs" : "Run of the mill spiderwebs.... only a lot bigger.",
    ]));

}