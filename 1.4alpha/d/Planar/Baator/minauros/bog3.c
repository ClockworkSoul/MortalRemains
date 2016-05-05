#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {    
    ::create();    
    set ("long", @EndText
The air here is particularly thick with the stench of death. All around
you are dozens of bodies, carefully placed in waist high water as if 
somehow pickling them. Through the oily rain and decaying trees you can
make out a ridge of razor-sharp obsidian, and the entrance to a cave.
EndText
    );
    set("item_desc", ([
    "bodies" : "They are all carefully arranged in rows. There are 23 "+
        "bodies in total.\n",
    "water" : "It is especially stagnant here.\n",
    "ridge" : "It cuts across the landscape from north to south, roughly.\n",
    "trees" : "They are unidentifiable, their leaves practically rotting off.\n",
    "cave" : "It seems somewhat drier in there, but it's too dark to tell.\n"
    ]) );
    set ("exits", ([
    "east" : BAATOR+"minauros/bog4.c",
    "south" : BAATOR+"minauros/bog8.c"
    ]));
}
