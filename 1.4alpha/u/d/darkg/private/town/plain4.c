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
   "west" : AROOM+"plain3.c",
   "south" : AROOM+"plain9.c",
   "east" : AROOM+"plain5.c",
]));
reset();
	}
