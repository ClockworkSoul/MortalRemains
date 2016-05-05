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
   "west" : AROOM+"plain15.c",
   "north" : AROOM+"plain8.c",
   "south" : AROOM+"plain22.c",
   "east" : AROOM+"plain17.c",
]));
reset();
	}
