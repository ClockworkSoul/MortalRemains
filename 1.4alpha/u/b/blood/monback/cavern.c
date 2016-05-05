#include <teleport.h>   
#include <mudlib.h>
#include "newbie.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );  
    set("no_teleport", NO_IN_OR_OUT);
    set("author","blood");
    set("objects", ([
      "dragon" : N_MON+"dragon.c",
    ]) );
    set( "short", "Dragon's Cavern" );
    set( "long", @EndText
Stalagmites and stalactites protrude from various places
within this cave. A large pool of lava, steams and bubbles
in the center of this room to keep it very, very hot.
Besides the sulfurous odor of the lava, you can also hear
sounds of heavy breathing associated with large plumes of
smoke.
EndText
    );
    reset();
}
