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
set("short","a rocky path");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
This path gets harder to climb as you stumble over the rocks. Those
strange noises continue on to the west, where you can make out a 
series of caves and a bright sign.
EndText
    );
    set( "exits", ([
"east":INS_ROOM+"path1.c",
"west":INS_ROOM+"path3.c",
    ]) );
    set("objects",([
"dog":INS_MON+"scrappy.c",
    ]) );


set("listen","The laughter is now mixed with a howling. Something odd is definately happening! \n");
set("item_desc", ([
"rocks" : "Some loose gravel that makes up this path. \n",
"caves" : "You are too far away to get a good look at them. \n",
"sign" : "It is too far away to read, but you can tell it has bright colors. \n",
]));
    reset();
}
