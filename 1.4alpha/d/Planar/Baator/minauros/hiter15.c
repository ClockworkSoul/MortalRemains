#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"hiterstd.c" ;

void create() {    
    ::create();
    add ("long", @EndText
To the east is a wide opening in the chains that make up the city walls,
through which a deep bog is visible.
EndText
    );
    set ("exits", ([   
    "east" : BAATOR+"minauros/bog11.c",
    "north" : BAATOR+"minauros/hiter10.c",
    "south" : BAATOR+"minauros/hiter20.c"
    ]));
}