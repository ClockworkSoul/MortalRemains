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
      "east" : BAATOR+"stygia/floe7.c",
      "south" : BAATOR+"stygia/floe5.c"]));
reset();
	}

int reset(){
object ob1, ob2;
seteuid(getuid());
::reset();
if (present("amnizu", this_object())) return 1;
ob1=clone_object(BAATOR+"monsters/amnizu.c");
ob1->move(this_object());
ob2=clone_object(BAATOR+"monsters/amnizu.c");
ob2->move(this_object());
return 1;
}