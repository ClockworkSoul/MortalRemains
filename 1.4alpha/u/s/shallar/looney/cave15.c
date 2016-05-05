#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
object cyc;
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","shallar");
set("short","Dance Hallway");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
This room opens up into a large hallway which is dominated by classical
architecture. The main feature here are large columns which support the 
ceiling. There are some doors to the west which you can go through.
EndText
    );
set("smell","There is the odor of plastar of paris.\n");
    set( "exits", ([
"east":INS_ROOM+"cave14.c",
"west":INS_ROOM+"cave16.c",
]));

set ("item_desc",([
"architecture":"The style of these decorations is Greek Revival. \n",
]));
set("pre_exit_func",([
"west" : "cyclops_check",
]));
reset ();
cyc = clone_object("/d/Prime/Cyanide/monsters/cyclops.c");
cyc -> move(TO);
}

int cyclops_check()
{
if(present("cyclops", TO));
{
write ("The cyclops won't let you disturb the performers. He's the new bouncer and takes his job seriously. \n");
return 1;
}
}

