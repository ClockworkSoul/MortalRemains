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
   "west" : AROOM+"plain1.c",
   "east" : AROOM+"plain3.c",
   "south" : AROOM+"plain7.c",
]));
reset();
	}
