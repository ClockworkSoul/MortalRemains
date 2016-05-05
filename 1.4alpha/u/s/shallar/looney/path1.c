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
    set("short","a winding path");
    // NB: "@EndText" should not have spaces after it.
    set( "long", @EndText
This is where the road and the rocky path meet together. The 
weather has gotten colder as you head into the mountains. To the
north, the town of Barrelhaven is located but that path is blocked
by a fallen tree. Off to the west is a rocky path winding up the 
hill. The strange sounds you heard on the road are definately
coming from that direction.
EndText
    );
    set( "exits", ([
      "south" : "/u/s/shallar/boneville/road3.c",
"north":"/u/s/shallar/boneville/road4.c",
"west":INS_ROOM+"path2.c",
    ]) );
set("listen","Growling sounds come from the north while the \n"+
"laughter and chaos continue to the west.\n");
    set("objects",([
      "rat" : "/u/s/shallar/monster/rat.c",
    ]) );
    set("pre_exit_func",([
      "north" : "block"
    ]));
set ("item_desc",([
"road":"The same dirt road you've been traveling on. \n",
"path":"The path gets rockier as it goes to the west. \n",
"tree": "This tree has been placed across the road by the rat \n"+
"creatures. They don't want anyone helping the people of \n"+
"Barrelhaven!\n",
]) );
    reset();
}
int block() {
    write("The fallen tree still blocks the path to the north.\n");
    return 1;
}
