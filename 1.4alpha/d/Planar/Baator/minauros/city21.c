#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndLong
This is a bare room constructed entirely of black stone. It contains no 
furnishings whatsoever, with the exception of a large hole in the floor.
EndLong
    );
    set ("short","Before a Portal");
    set("item_desc", ([
    "hole" : "Hot air flows from it. It seems to be some kind of portal.\n",
    "stone" : "The same black rock the rest of the city is built of.\n"
    ]) );
    set ("exits", ([   
    "down" : BAATOR+"phlegethos/city15.c",
    "east" : BAATOR+"minauros/city22.c"
    ]));
}