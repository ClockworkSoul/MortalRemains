#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the fifth layer of Baator.\n"+
"You are along the banks of the fetid.\n"+
"River Styx, the river of forgetfulness.\n");
set ("short","River Styx, Stygia");
     set ("exits", ([
     "east" : BAATOR+"stygia/tcity16.c",
      "southeast" : BAATOR+"stygia/styx3.c",
         "northwest" : BAATOR+"stygia/styx1.c"]));
reset();
	}
