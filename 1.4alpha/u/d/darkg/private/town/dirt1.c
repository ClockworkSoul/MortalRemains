#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
    set("long", @ENDTEXT
You find yourself on a dirt road that is'nt used
much.  To the southwest is a vast open plain.
While the path continues to the northeast.
ENDTEXT);
set ("short","Dirt road");
     set ("exits", ([
   "southwest" : AROOM+"plain3.c",
   "northeast" : AROOM+"dirt2.c",
]));
reset();
	}
