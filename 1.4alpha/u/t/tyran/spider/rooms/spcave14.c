/* This is Room 2 of the Rock Tunnel leading from
the Spider Caves to the Lair of the Widow of the Web.
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
        set( "short", "The Rock Tunnel" );
        set( "long", @EndText
   The tunnel continues here.  The walls have 
turned from a dull grey to black in color.  
The spiderwebs are more pronounced and 
plentiful here.
EndText
        );

set( "exits", ([
"west" : SPD_ROOM+"spcave13.c",
"north" : SPD_ROOM+"spcave15.c",
        ]) );

    reset();
    smspidey = clone_object(SPD_MON+"smspidey.c");
    smspidey->move(TO);
set("item_desc", ([
    "ceiling" : "The ceiling is made of smooth obsidian rock.\n",
    "walls" : "The walls are made of smooth obsidian rock.  It's cool to the touch.\n",
    "wall" : "The walls are made of smooth obsidian rock. It's cool to the touch.\n",
    "floor" : "The floor is made of smooth obsidian rock.  A couple webs are anchored.\n",
    "webs" : "Run of the mill spiderwebs.... only a lot bigger.",
    ]));
}
void init () {
    add_action("touch_walls", "touch");
 
}
int touch_walls(string str) {
    if (!str || str!="walls") {
        write("touch what?\n");
        return 1;
    }
    say(TPN+" gently touches the walls of the caves.\n");
    write(wrap(
        "You gently feel the walls of the cave.\n"+
        "They feel cool to the touch.\n"));
    return 1;
}