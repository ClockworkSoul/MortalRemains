#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("long", @EndLong
You are on the wide main street running though the Sinking City. All manner
of bizarre demon and fiend walk on this road, casting you sidelong glances
as you pass. To the east you can make out a large palace of black stone. To
the west you can barlely make out the massive gates of the city.
EndLong
    );
    set ("short","Main Street of Minauros");
    set ("exits", ([   
    "west" : BAATOR+"minauros/city18.c",
    "south" : BAATOR+"minauros/city26.c",
    "east" : BAATOR+"minauros/city20.c" 
    ]));
}