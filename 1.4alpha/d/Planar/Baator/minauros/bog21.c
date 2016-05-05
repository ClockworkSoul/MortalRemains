#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
You are standing waist-deep in black, stagnant water. As you move,
unidentifiable objects bump against your legs, many of which are grotesquely
soft. A sharp ridge of black volcanic glass cuts into the water from the
north, and you have to take great care from cutting yourself on it as you
pass over it. There is a shore of sorts to your north.
EndText
    );

    add("item_desc", ([
      "shore" : "Well, the water there is merely ankle deep.\n",
      "glass" : "It looks like a natural phenomenon.\n",
      "pond" : "You would prefer to spend as little time here as possible.\n",
      "objects" : "They feel alot like... bodies.\n",
      "legs" : "You already know what THEY look like.\n",
      "water" : "It is thick and black. Completely opaque.\n",
    ]) );
    set ("short","In a Scum Covered Pond");
    set ("exits", ([   
      "east" : BAATOR+"minauros/bog22.c",  
      "west" : BAATOR+"minauros/bog20.c",
      "north" : BAATOR+"minauros/bog15.c"
    ]));
}

void populate() {;}
