

#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short" , "Eastern Cavern" );
    set( "long", @EndText
When you enter this cavern you notice that it becomes 
very bright.  All of the shadow's that were following you
are now here with you in this room.  They have you
surrounded and are blocking the way out.  You also notice
taht the walls are made of mud, and there are pools of
blood on the floor.
EndText
    );
    set( "exits", ([
"west" : KYRIE+"kyrie4.c",
    ]) );
}
