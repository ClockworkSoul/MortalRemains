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
   "north" : AROOM+"plain1.c",
   "west" : AROOM+"plain12.c",
]));
reset();
	}
