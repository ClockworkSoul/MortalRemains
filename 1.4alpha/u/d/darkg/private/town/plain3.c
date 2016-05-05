#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
    set("long", @ENDTEXT
ENDTEXT);
set ("short","Grassy plains");
     set ("exits", ([
   "east" : AROOM+"plain4.c",
   "south" : AROOM+"plain8.c",
   "west" : AROOM+"plain2.c",
   "northeast" : AROOM+"dirt1.c",
]));
reset();
	}
