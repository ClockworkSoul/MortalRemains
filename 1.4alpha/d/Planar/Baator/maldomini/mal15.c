#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, in the antechamber to Triel the fallen. \n"+
"Lord of this layer.\n");
set ("short","Maldomini, the seventh hell.");
     set ("exits", ([
     "south" : BAATOR+"maldomini/mal16.c",
         "north" : BAATOR+"maldomini/mal12.c"]));
reset();
	}
