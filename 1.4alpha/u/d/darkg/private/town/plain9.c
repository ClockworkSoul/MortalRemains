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
   "north" : AROOM+"plain4.c",
   "east" : AROOM+"plain10.c",
   "west" : AROOM+"plain8.c",
   "south" : AROOM+"plain17.c",
]));
reset();
	}
