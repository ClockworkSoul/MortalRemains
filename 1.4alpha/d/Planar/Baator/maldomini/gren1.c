#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, the seventh layer of Baator.\n"+
"A sign near the portal reads:\n"+
"Welcome to Grenpoli, City of diplomacy.\n");
set ("short","Grenpoli, Maldomini, the seventh hell.");
     set ("exits", ([
"south" : BAATOR+"maldomini/gren3.c",
 "portal" : BAATOR+"malbolge/mal13.c"]));
reset();
	}
