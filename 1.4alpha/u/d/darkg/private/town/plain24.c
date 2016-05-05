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
   "north" : AROOM+"plain18.c",
   "west" : AROOM+"plain23.c",
   "south" : AROOM+"swamp1.c",
]));
reset();
	}
