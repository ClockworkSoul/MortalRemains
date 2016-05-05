#include <config.h>
#include <mudlib.h>
#include "insane.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","shallar");
set("short","crash site");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
This part of the caves opens up into a wide passage. You notice that 
there is agreat deal of mechanical wreckage around you. Sunlight filters
through a hole in the ceiling cause by an apparent collision of
two crafts. A portal stands open near one of the crafts.
EndText
    );
set("smell","You smell smoke and burning fuel. This must have been some crash!\n");
    set( "exits", ([
"west":INS_ROOM+"cave1.c",
"portal":INS_ROOM+"cave11.c",
]));

set ("item_desc",([
"wreckage":"The twisted pieces of metal from this crash. \n",
"hole":"A large hole in the cave. It must have been caused by \n" +
" the landing of the ships.\n",
"crafts":"There are two crafts here. One looks like a submarine and \n" +
" the other is a green ship not from this world. \n",
"submarine":"This is a yellow submarine that incredibly enough was \n" +
" able to fly at one time. It looks like it was heading to that portal. \n",
"portal": "A portal to another world. You wonder where that will go... \n",
"ship" : "This is a large green ship with the words: Mars or Bust! \n" +
" on the side of it. You guess it busted cause this ain't Mars. \n",
]));
}

void reset(){
object marv, max;

if(!present("marvin", this_object())) {
marv = clone_object(INS_MON+"marv.c");
marv -> move(this_object());
}

if(!present("max", this_object())){
max = clone_object (INS_MON+"max.c");
max -> move(this_object());
}
}
