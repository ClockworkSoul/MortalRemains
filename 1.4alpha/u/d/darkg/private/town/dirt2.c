#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
    set("long", @ENDTEXT
The road is rather rough and in need of repair.
It streches far to the northeast and southwest.
ENDTEXT);
set ("short","Dirt road");
     set ("exits", ([
   "northeast" : AROOM+"dirt3.c",
   "southwest" : AROOM+"dirt1.c",
]));
reset();
	}
