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
         "east" : BAATOR+"stygia/tcity19.c"]));
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