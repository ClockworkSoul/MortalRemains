#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in the sinking city of Minauros itself.\n"+
"Demons search for stray mortals to devour.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
   	     	  "west" : BAATOR+"minauros/city32.c"]));
reset();
	}
int reset(){
object ob1, ob2, ob3;
::reset();
 seteuid(getuid()) ;  
if (present("hamatula", this_object())  ) return 1;
ob1 = clone_object(BAATOR+"monsters/hamatula");
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/hamatula");
ob2->move(this_object());
ob3 = clone_object(BAATOR+"monsters/hamatula");
ob3->move(this_object());
ob1->set("protectors", ({ ob2, ob3 }));
ob1->set("protectees", ({ ob2, ob3 }));
ob2->set("protectors", ({ ob1, ob3 }));
ob2->set("protectees", ({ ob1, ob3 }));
ob3->set("protectors", ({ ob2, ob1 }));
ob3->set("protectees", ({ ob2, ob1 }));
return 1;
}

