#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"an abandoned building.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
         "north" : BAATOR+"maldomini/gren15.c"]));
reset();
	}
