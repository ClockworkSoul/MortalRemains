#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects" , ([ 	"pitfiend" : BAATOR+"monsters/pit_fiend"]));
    set ("light", 1) ;
    set ("long", @EndLong
You are within a the massive iron tower of the Dispater, the Archduke of
Dis, on the ground level. A ponderous spiral stairwell runs up and down
here, and a great archway leads out to the west.
EndLong
    );
    set ("short","The Iron Tower of Dis");
    set ("exits", ([
      "west" : BAATOR+"dis/dcity18.c",
      "down" : BAATOR+"dis/dtower2.c",
      "up" : BAATOR+"dis/dtower4.c"
      ]));
    reset();
}
