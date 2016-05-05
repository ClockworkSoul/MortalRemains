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
   "west" : AROOM+"plain22.c",
   "east" : AROOM+"plain24.c",
   "north" : AROOM+"plain17.c",
]));
reset();
	}
