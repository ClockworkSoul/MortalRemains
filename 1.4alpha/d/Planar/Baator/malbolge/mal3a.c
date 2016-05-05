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
     "up" : BAATOR+"malbolge/mal3b.c",
     "down" : BAATOR+"malbolge/mal3.c",
     "southeast" : BAATOR+"malbolge/mal8a.c",
     "southwest" : BAATOR+"malbolge/mal6a.c"]));
reset();
	}
