#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"There are bandages laying about in piles in this building.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
         "east" : BAATOR+"maldomini/gren6.c"]));
reset();
	}
