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
"You presume that this tower holds some important\n"+
"Demon for it rises high into the air.\n"+
"A still taller tower looms in the distance and a somewhat\n"+
"Smaller one lies to the south.\n");
set ("short","Malbolge, the sixth hell of Baator.");
     set ("exits", ([
     "down" : BAATOR+"malbolge/mal3a.c",
     "south" : BAATOR+"malbolge/mal23b.c"]));
reset();
	}
