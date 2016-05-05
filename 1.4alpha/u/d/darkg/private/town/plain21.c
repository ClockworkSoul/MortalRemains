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
   "east" : AROOM+"plain22.c",
   "north" : AROOM+"plain15.c",
   "west" : AROOM+"plain20.c",
]));
reset();
	}
