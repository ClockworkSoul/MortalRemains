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
"Stairs lead up to the top and down into darkness.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "south" : BAATOR+"malbolge/mal23c.c",
     "down" : BAATOR+"malbolge/mal13b.c",
     "up" : BAATOR+"malbolge/mal13d.c"]));
reset();
	}
