#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"The street turns north and east.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
     "north" : BAATOR+"maldomini/gren10.c",
          "east" : BAATOR+"maldomini/gren14.c"]));
reset();
	}
