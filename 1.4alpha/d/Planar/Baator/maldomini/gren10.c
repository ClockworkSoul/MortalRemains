#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"The street leads north and south.\n"+
"A courthouse lies to the west.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
     "north" : BAATOR+"maldomini/gren6.c",
     "south" : BAATOR+"maldomini/gren13.c",
          "west" : BAATOR+"maldomini/gren9.c"]));
reset();
	}
