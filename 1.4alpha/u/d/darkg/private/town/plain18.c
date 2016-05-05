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
   "west" : AROOM+"plain17.c",
   "north" : AROOM+"plain10.c",
   "south" : AROOM+"plain24.c",
   "east" : AROOM+"plain19.c",
]));
reset();
	}
