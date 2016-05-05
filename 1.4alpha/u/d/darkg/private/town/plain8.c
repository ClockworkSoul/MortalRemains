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
   "south" : AROOM+"plain16.c",
   "west" : AROOM+"plain7.c",
   "east" : AROOM+"plain9.c",
   "north" : AROOM+"plain3.c",
]));
reset();
	}
