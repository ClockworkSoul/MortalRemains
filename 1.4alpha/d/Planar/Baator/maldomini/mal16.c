#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"Maldomini, in the throne room of Triel the fallen. \n"+
"Lord of this layer.\n");
set ("short","Maldomini, the seventh hell.");
     set ("exits", ([
             "north" : BAATOR+"maldomini/mal15.c"]));
reset();
	}
int reset(){
object ob1, ob2;
seteuid(getuid());
::reset();
if (present("triel", this_object())) return 1;
ob1=clone_object(BAATOR+"monsters/triel.c");
ob1->move(this_object());
return 1;
}