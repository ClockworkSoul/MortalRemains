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
   "west" : AROOM+"plain21.c",
   "north" : AROOM+"plain16.c",
   "east" : AROOM+"plain23.c",
]));
reset();
	}
