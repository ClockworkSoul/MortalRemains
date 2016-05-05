#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("short", "A Narrow Tunnel" );
    set( "long", @EndText
You are tight, narrow tunnel. An ancient and water-carved ravine
winds through the cavern, with a small stream at the bottom. The walls
of the ravine are steep and crumbly. A foot bridge crosses the ravine
to the south.
EndText
    );
    set( "exits", ([
      "up" : MAIN+"/infstair2.c",
      "south" : MAIN+"/ftbridge.c",
      "down" : MAIN+"/crevasse.c",
      "climb" : MAIN+"/crevasse.c",
    ]) );
    set ("exit_suppress", ({"down", "climb"}) );
    set ("item_desc", ([
      "ravine" : "To climb it would be suicide, probably...\n",
      "bridge" : "The old wooden foot bridge looks pretty sturdy from here.\n",
    ]) );
}

void reset () {
    object knight;
    ::reset ();
    seteuid( getuid());
    if(present("knight",this_object())) return;
    knight=clone_object(MONST+"/wounded_man.c");
    knight->move(this_object());
}

