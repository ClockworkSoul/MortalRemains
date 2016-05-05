#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the sixth layer of Baator.\n"+
"You step upon the walkway.\n"+
"The highest tower lies to the north.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "down" : BAATOR+"malbolge/mal23b.c",
     "north" : BAATOR+"malbolge/mal13c.c"]));
reset();
	}
