#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("long", @EndLong
You are on the wide main street running though the Sinking City. All manner
of bizarre demon and fiend walk on this road, casting you sidelong glances
as you pass. To the east is the entrance to the Inner Palace, heavily guarded.
The main road continues to the north.
EndLong
    );
    set ("short","Main Street of Minauros");
    set ("exits", ([   
    "north" : BAATOR+"minauros/city20.c",
    "east" : BAATOR+"minauros/city28.c"
    ]));
}