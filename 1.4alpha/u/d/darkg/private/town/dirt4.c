#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
    set("long", @ENDTEXT
Just east of here is a rather busy town.
While southwest is a dead dirt road.
ENDTEXT);
set ("short","Dirt road");
     set ("exits", ([
   "east" : AROOM+"street1.c",
   "southwest" : AROOM+"dirt3.c",
]));
reset();
	}
