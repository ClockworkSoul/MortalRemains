#include "kyrie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()

{
    ::create();
    
    seteuid( getuid() );
    set( "light", 1 );  
    set("author","valkyrie");
    set( "short", "Strange Path" );
    set( "long", @EndText
There is a small but well-worn path through the verdant woods here. The
trees are thick overhead and around you, and there is a great deal of
underbrush. The air seems strangely still for such a wooded area, but you
don't think much of it.  The path seems to run east, deeper into the
woods, or west towards town.
EndText
    ); 
    set( "exits", ([
      "east" : KYRIE+"kyrie9.c",
    ]) );
}

