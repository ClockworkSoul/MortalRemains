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
         "northwest" : BAATOR+"stygia/styx3.c"]));
reset();
	}
