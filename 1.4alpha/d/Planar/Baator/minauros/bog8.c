#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
Suddenly, seemingly out of nowhere the path abruptly ends, interrupted by
a sheer ridge of razor-sharp obsidian. It seems that the path turns
sharply north to compensate.
EndText
    );
    set ("exits", ([     
    "west" : BAATOR+"minauros/bog7.c",
    "north" : BAATOR+"minauros/bog3.c",
    ]));
    reset();
}
