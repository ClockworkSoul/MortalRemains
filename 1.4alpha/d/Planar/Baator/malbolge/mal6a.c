#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the sixth layer of Baator.\n"+
"You are in one of the many vast towers\n"+
"of this layer.\n"+
"A central tower rises above the rest.\n"+
"Walkways connect the towers at this level.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "down" : BAATOR+"malbolge/mal6.c",
     "south" : BAATOR+"malbolge/mal18a.c",
     "northeast" : BAATOR+"malbolge/mal3a.c",
     "southwest" : BAATOR+"malbolge/mal11a.c"]));
reset();
	}
