#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"citystd.c" ;

void create() {    
    ::create();
    set ("long", @EndText
You are in the reception hall of the Inner Palace of Minauros. To the
north is the throne room, and the gates outside are to the west.
EndText
    );
    set ("short","The Reception Hall");
    set ("exits", ([   
    "north" : BAATOR+"minauros/city22.c",
    "west" : BAATOR+"minauros/city28.c"
    ]));
    reset();
}


