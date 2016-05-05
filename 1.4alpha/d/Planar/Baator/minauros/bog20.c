#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
You are standing waist-deep in black, stagnant water. As you move,
unidentifiable objects bump against your legs, many of which are 
grotesquely soft. The water gets shallower to the north and west.
EndText
    );
    add("item_desc", ([
      "pond" : "You would prefer to spend as little time here as possible.\n",
      "objects" : "They feel alot like... bodies.\n",
      "legs" : "You already know what THEY look like.\n",
      "water" : "It is thick and black. Completely opaque.\n",
    ]) );
    set ("short","In a Scum Covered Pond");
    set ("exits", ([   
      "west" : BAATOR+"minauros/bog19.c",
      "east" : BAATOR+"minauros/bog21.c",  
      "north" : BAATOR+"minauros/bog14.c",
      "south" : BAATOR+"minauros/bog26.c"
    ]));
}


void populate() { ; }
