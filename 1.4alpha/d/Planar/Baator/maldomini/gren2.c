#include <mudlib.h>
#include "baator.h"

inherit PUB ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"A demon is selling beverages out of the back of a wagon here.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
         "east" : BAATOR+"maldomini/gren3.c"]));
reset();
	}
