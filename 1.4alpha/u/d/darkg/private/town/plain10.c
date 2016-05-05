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
   "south" : AROOM+"plain18.c",
   "west" : AROOM+"plain9.c",
   "east" : AROOM+"plain11.c",
   "north" : AROOM+"plain5.c",
]));
reset();
	}
