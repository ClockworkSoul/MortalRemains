#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the sixth layer of Baator.\n"+
"You are on the rocky slopes of Malbolge,\n"+
"Where brass fortresses protect the inhabitants from\n"+
"The constantly shifting terrain.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "east" : BAATOR+"malbolge/mal18.c",
     "northwest" : BAATOR+"malbolge/mal10.c",
     "northeast" : BAATOR+"malbolge/mal12.c",
     "southeast" : BAATOR+"malbolge/mal22.c"]));
reset();
	}
