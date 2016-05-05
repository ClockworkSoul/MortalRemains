#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("objects" , ([ 	"amnizu" : BAATOR+"monsters/amnizu"]));
    set ("light", 1) ;
    set ("long", @EndLong
You are within a the massive iron tower of the Dispater, the 
Archduke of Dis. A ponderous spiral stairwell runs up and down here.
EndLong
    );
    set ("short","The Iron Tower of Dis");
    set ("exits", ([
      "down" : BAATOR+"dis/dtower4.c",
      "up" : BAATOR+"dis/dtower6.c"
      ]));
    reset();
}
