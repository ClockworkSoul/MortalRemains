#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the sixth layer of Baator.\n"+
"You are at the entrance to a vast,\n"+
"Fortress made of brass.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "up" : BAATOR+"malbolge/mal23a.c",
     "north" : BAATOR+"malbolge/mal19.c"]));
reset();
	}
