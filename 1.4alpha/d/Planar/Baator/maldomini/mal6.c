#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"Beware traveler! and be wary!, for\n"+
"Predators hunt the wastes between the two cities.\n");
set ("short","Maldomini, the seventh hell.");
     set ("exits", ([
     "west" : BAATOR+"maldomini/gren15.c",
         "north" : BAATOR+"maldomini/mal1.c"]));
reset();
	}
