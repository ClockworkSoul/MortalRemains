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
"Predators hunt the wastes between the two cities.\n"+
"Malagard, the city, lies to the south.\n");
set ("short","Maldomini, the seventh hell.");
     set ("exits", ([
     "west" : BAATOR+"maldomini/mal3.c",
         "south" : BAATOR+"maldomini/mal8.c"]));
reset();
	}
