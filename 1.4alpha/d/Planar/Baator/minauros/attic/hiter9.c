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
  "south" : BAATOR+"minauros/hiter14.c",
          "west" : BAATOR+"minauros/hiter8.c"]));
reset();
	}
int reset(){
object ob1, ob2, ob3;
::reset();
 seteuid(getuid()) ;  
if (present("kyton", this_object()) ) return 1;
ob1 = clone_object(BAATOR+"monsters/kyton");
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/kyton");
ob2->move(this_object());
ob3 = clone_object(BAATOR+"monsters/kyton");
ob3->move(this_object());
return 1;
}

