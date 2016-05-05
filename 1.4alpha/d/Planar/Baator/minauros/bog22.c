#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
You are standing waist-deep in black, stagnant water. As you move,
unidentifiable objects bump against your legs, many of which are grotesquely
soft. The edge of the pond is to the north and to the east.
EndText
    );

    add("item_desc", ([
      "edge" : "It is to your east.\n",
      "pond" : "You would prefer to spend as little time here as possible.\n",
      "objects" : "They feel alot like... bodies.\n",
      "legs" : "You already know what THEY look like.\n",
      "water" : "It is thick and black. Completely opaque.\n",
    ]) );
    set ("short","In a Scum Covered Pond");
    set ("exits", ([     
      "west" : BAATOR+"minauros/bog21.c",
      "north" : BAATOR+"minauros/bog16.c",
      "east" : BAATOR+"minauros/bog23.c"
    ]) );
}

void populate() {;}
