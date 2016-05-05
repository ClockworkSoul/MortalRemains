#include <mudlib.h>
#include "fuckstick.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
    set("long", @ENDTEXT
ENDTEXT);
set ("short","Rolling hills");
     set ("exits", ([
   "west" : AROOM+"path1.c",
   "north" : AROOM+"plain12.c",
   "east" : AROOM+"plain14.c",
]));
reset();
	}
