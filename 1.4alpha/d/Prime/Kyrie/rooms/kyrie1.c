
#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short", "Entrance to Kyrie forest" );
    set( "long" , @EndText
You are entering the forest of Kyrie, as you are walking along the
path you keep seeing a shadow that isn't yours following.  You
really feel uncomfortable here.  The forest is very dark and feels
haunted.  There is a little peaceful stream that flows here and it
seems to be the only thing with any brightness to it here.
EndText
    );
    set( "exits", ([
      "north" : KYRIE+"kyrie2.c",
    ]) );
}
