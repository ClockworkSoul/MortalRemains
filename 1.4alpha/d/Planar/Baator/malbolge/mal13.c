#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the sixth layer of Baator.\n"+
"You are in the fortress of the lord of this layer.\n"+
"Stairs lead up to the next level.\n"+
"There is a shimmering portal of darkness here.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "up" : BAATOR+"malbolge/mal13a.c",
"portal" : BAATOR+"pit7.c"]));
reset();
	}
