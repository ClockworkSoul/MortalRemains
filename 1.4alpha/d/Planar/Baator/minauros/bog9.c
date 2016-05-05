#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("long", @EndText
Suddenly, seemingly out of nowhere the path abruptly ends, interrupted by
a sheer ridge of razor-sharp obsidian. It seems that the path winds east 
and south to compensate.
EndText
    );
    set ("exits", ([   
    "east" : BAATOR+"minauros/bog10.c",  
    "south" : BAATOR+"minauros/bog16.c"
    ]));
    reset();
}
