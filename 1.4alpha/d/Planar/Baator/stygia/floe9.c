#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the fifth layer of Baator.\n"+
"You wander within an icy labryinth.\n"+
"Shadowy forms seem to mock your vision.\n"+
"You sense that this place harbors great danger.\n");
set ("short","Ice Floe, Stygia");
     set ("exits", ([
      "north" : BAATOR+"stygia/floe10.c",
      "east" : BAATOR+"stygia/floe8.c"]));
reset();
	}
