#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in a city of chains.\n"+
"Chains reach into the skies and even the buildings themselves.\n"+
"Are fashioned from this odd material.\n");
set ("short","Jangling Hiter, city of chains");
     set ("exits", ([   
  "north" : BAATOR+"minauros/hiter16.c"]));
reset();
	}
int reset(){
object ob1, ob2, ob3;
::reset();
 seteuid(getuid()) ;  
if (present("osyluth", this_object()) ) return 1;
ob1 = clone_object(BAATOR+"monsters/osyluth");
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/osyluth");
ob2->move(this_object());
ob1->set("aggressive", 9);
ob2->set("aggressive", 9);
return 1;
}

