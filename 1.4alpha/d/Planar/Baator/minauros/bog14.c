#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
The ground here is particularly soft, and you sink almost knee deep in the
muck. The stagnant water deepens to the south, becoming a shallow pond. To
the east, a razor sharp ridge of black glass cuts through the landscape 
running from the north, and disappearing into the pond.
EndText
    );
    set ("short","The Stinking Bogs of Minauros");
    set ("exits", ([       
        "west" : BAATOR+"minauros/bog13.c",
        "north" : BAATOR+"minauros/bog7.c",
        "south" : BAATOR+"minauros/bog20.c"
    ]));
    set("extra_look", ([
    "ridge" : "It seems very out of place here, but it's quite real.\n",
    "ground" : "Little more than very soggy mud, it sucks at your feet.\n",
    "water" : "It is foul beyond words.\n",
    "pond" : "More of a deep spot in the normally ankle-deep water.\n"
    ]) );
    reset();
}
