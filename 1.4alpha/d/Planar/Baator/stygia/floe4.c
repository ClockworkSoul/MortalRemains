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
"Shadowy forms seem to mock your vision.\n");
set ("short","Ice Floe, Stygia");
     set ("exits", ([
      "north" : BAATOR+"stygia/floe3.c",
      "east" : BAATOR+"stygia/floe5.c"]));
reset();
//put 2 geulugons here.
	}
