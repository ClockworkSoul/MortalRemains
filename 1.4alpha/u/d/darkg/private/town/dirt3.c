#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
    set("long", @ENDTEXT
To the northeast you can start to make out 
what looks to be a town forming. continuing
southwest is a long dirt road not used often.
ENDTEXT);
set ("short","Dirt road");
     set ("exits", ([
   "southwest" : AROOM+"dirt2.c",
   "northeast" : AROOM+"dirt4.c",
]));
reset();
	}
