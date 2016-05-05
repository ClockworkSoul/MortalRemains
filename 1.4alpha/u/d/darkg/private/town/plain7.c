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
   "north" : AROOM+"plain2.c",
   "east" : AROOM+"plain8.c",
   "south" : AROOM+"plain15.c",
]));
reset();
	}
