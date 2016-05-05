#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"Buildings lie to the north and south,\n"+
"The street continues east and west.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
     "north" : BAATOR+"maldomini/gren11.c",
     "south" : BAATOR+"maldomini/gren16.c",
     "east" : BAATOR+"maldomini/gren14.c",
     "west" : BAATOR+"maldomini/gren13.c"
     ]));
reset();
}