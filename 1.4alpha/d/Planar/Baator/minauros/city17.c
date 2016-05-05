#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("long", @EndLong
You are on the wide main street running though the Sinking City. All manner
of bizarre demon and fiend walk on this road, casting you sidelong glances
as you pass. Far to the east you can make out a palace of sorts, and to your
immediate west are the gates of the city.
EndLong
    );
    set ("short","Main Street of Minauros");
    set ("exits", ([   
    "north" : BAATOR+"minauros/city10.c",
    "south" : BAATOR+"minauros/city24.c",
    "east" : BAATOR+"minauros/city18.c",
    "west" : BAATOR+"minauros/city16.c"
    ]));
}


