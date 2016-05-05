#include <config.h>   
#include <mudlib.h>

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set( "light", 1 );  
    set("author","blood");
    set("objects", ([
"dragon" : "/d/Prime/Magehouse/monsters/dragon.c"
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
}
