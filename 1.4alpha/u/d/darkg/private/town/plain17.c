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
   "east" : AROOM+"plain18.c",
   "south" : AROOM+"plain23.c",
   "north" : AROOM+"plain9.c",
   "west" : AROOM+"plain16.c",
]));
reset();
	}
