#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {
    ::create();
    set ("long", @EndText
The ground here is particularly soft, and you sink almost knee deep in the
muck. The stagnant water deepens to the south, becoming a shallow pond. To
the west, a razor sharp ridge of black glass cuts through the landscape 
running from the north, and disappearing into the pond.
EndText
    );    
    set("extra_look", ([
    "ridge" : "It seems very out of place here, but it's quite real.\n",
    "ground" : "Little more than very soggy mud, it sucks at your feet.\n",
    "water" : "It is foul beyond words.\n",
    "pond" : "More of a deep spot in the normally ankle-deep water.\n"
    ]) );
    set ("exits", ([   
    "east" : BAATOR+"minauros/bog16.c",  
    "south" : BAATOR+"minauros/bog21.c"
    ]));
    reset();
}
