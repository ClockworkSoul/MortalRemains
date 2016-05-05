#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects", ([ "red" : BAATOR+"monsters/paragonred.c" ]) );
    set ("light", 1) ;
    set ("long", @EndLong
You are within a the massive iron tower of the Dispater, the 
Archduke of Dis. A ponderous spiral stairwell runs up here. Across the
room is a massive glowing portal. Nearby, a massive chain, its links as
large as your torso, restains a massive beast of incredible proprtions.
EndLong
    );
    set ("short","The Iron Tower of Dis");
    set ("exits", ([
      "portal" : BAATOR+"minauros/hiter13.c",
      "up" : BAATOR+"dis/dtower2.c"
    ]));
    reset();
}
