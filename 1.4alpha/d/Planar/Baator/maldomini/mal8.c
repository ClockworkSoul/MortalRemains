#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, in the city of Malagard.\n"+
"None dare oppose the power of the lords of hell.\n"+
"Especially within this city.\n");
set ("short","Maldomini, the seventh hell.");
     set ("exits", ([
     "north" : BAATOR+"maldomini/mal4.c",
     "south" : BAATOR+"maldomini/mal12.c",
     "east" : BAATOR+"maldomini/mal9.c",
     "west" : BAATOR+"maldomini/mal7.c"]));
reset();
	}
