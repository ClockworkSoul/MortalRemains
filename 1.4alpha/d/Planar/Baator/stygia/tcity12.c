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
      "south" : BAATOR+"stygia/tcity17.c",
     "north" : BAATOR+"stygia/tcity7.c"]));
reset();
}

int reset(){
object ob1, ob2;
seteuid(getuid());
::reset();
if (present("cornugon", this_object())) return 1;
ob1=clone_object(BAATOR+"monsters/cornugon.c");
ob1->move(this_object());
ob2=clone_object(BAATOR+"monsters/cornugon.c");
ob2->move(this_object());
return 1;
}