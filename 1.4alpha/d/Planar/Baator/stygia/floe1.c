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
      "west" : BAATOR+"stygia/tcity10.c",
      "south" : BAATOR+"stygia/floe2.c"]));
reset();
	}

int reset(){
object ob1, ob2;
seteuid(getuid());
::reset();
if (present("gelugon", this_object())) return 1;
ob1=clone_object(BAATOR+"monsters/gelugon.c");
ob1->move(this_object());
ob2=clone_object(BAATOR+"monsters/gelugon.c");
ob2->move(this_object());
return 1;
}
