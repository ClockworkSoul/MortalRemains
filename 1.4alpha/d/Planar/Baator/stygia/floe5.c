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
"You feel as though you are being watched.\n");
set ("short","Ice Floe, Stygia");
     set ("exits", ([
      "north" : BAATOR+"stygia/floe6.c",
      "west" : BAATOR+"stygia/floe4.c"]));
reset();
	}
