#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("author", "cyanide");
    set ("light", 1) ;
    set ("long", @EndLong
You are at the very top of tower of Dispater, the Archduke of Dis. From
here, you can see miles in all directions across the grey-green planes of
Dis. A ponderous spiral stairwell runs down here.
EndLong
    );
    set ("short","The Iron Tower of Dis");
    set ("exits", ([
      "down" : BAATOR+"dis/dtower7.c"
    ]));
    reset();
}
