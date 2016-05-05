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
          "south" : BAATOR+"stygia/floe9.c"]));
reset();
	}

int reset(){
object ob1, ob2;
seteuid(getuid());
::reset();
if (present("levistus", this_object())) return 1;
ob1=clone_object(BAATOR+"monsters/levistus.c");
ob1->move(this_object());
return 1;
}