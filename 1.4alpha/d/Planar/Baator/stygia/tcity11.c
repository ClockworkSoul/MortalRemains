#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the fifth layer of Baator.\n"+
"You are in the chilling city of Tantlin.\n"+
"Blood spattered snow fills the alleys between.\n"+
"the frozen buildings.\n");
set ("short","Tantlin, Stygia");
     set ("exits", ([
      "south" : BAATOR+"stygia/tcity16.c",
     "north" : BAATOR+"stygia/tcity6.c"]));
reset();
	}
