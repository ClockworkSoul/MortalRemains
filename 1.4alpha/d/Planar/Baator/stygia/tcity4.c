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
      "east" : BAATOR+"stygia/tcity5.c",
     "west" : BAATOR+"stygia/tcity3.c"]));
reset();
	}
