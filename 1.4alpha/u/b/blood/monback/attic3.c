#include "newbie.h"
#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{   
    ::create();
    seteuid( getuid() );
    set( "light", 1 );
    set("author","blood");
    set( "short", "The Attic" );
    set( "long", @EndText
As you enter the attic, the smell of dust and old wood
assaults your nostrils. Crossbeams made of oak zigzag
over your head to form a spell of protection that shields
the entire house from unknown magical forces. You also
notice you are starting to sweat heavily.
EndText
    );
                    
    set( "exits", ([      
      "west" : N_ROOM+"attic4.c",
      "east" : N_ROOM+"attic2.c"
    ]) );
}
