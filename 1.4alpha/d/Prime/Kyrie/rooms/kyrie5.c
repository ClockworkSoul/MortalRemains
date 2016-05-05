

#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set( "short" , "Western Cavern" );
    set( "long", @EndText
As you enter this cavern you notice that it doesn't seem as
clean as the other cavern.  You also notice that the mud that
makes up the walls is very soft.  There is a pile of fresh
bones in one of the corners of the cavern.
EndText
    );
    set( "exits", ([
"east" : KYRIE+"kyrie4.c",
    ]) );
}
