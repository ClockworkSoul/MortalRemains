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
"Only one tower is taller than this one.\n"+
"Stairs up lead to the walkway.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "up" : BAATOR+"malbolge/mal23c.c",
     "north" : BAATOR+"malbolge/mal3b.c"]));
reset();
	}
