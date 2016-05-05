#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
You are standing neck-deep in the deepest part of the stagnant pond, trying
desperately not to inhale any of the indescribably foul water. A water-bloated
corpse bobs at the edge of the pond, and occasionally you feel something alive
brush against your leg. You can swim north toward shallower water, or east
toward a deeper, reed-concealed part of the pond.
EndText
    );
    set ("short","In a Scum Covered Pond");
    set ("exits", ([     
      "north" : BAATOR+"minauros/bog20.c",
      "east" : BAATOR+"minauros/bog27.c"
    ]));
    add("item_desc", ([
      "corpse" : "It's bloated beyond all hopes of recognition.\n",
      "pond" : "You would really rather not do that.\n"
    ]) );
    reset();
}

void populate() { ; }
