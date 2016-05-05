#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the fourth layer of Baator.\n"+
"You are in the city of Abriymoch in Phlegethos.\n"+
"It is seated within an active volcano.\n"+
"You wind you way amongst running lava and choking gases.\n");
set ("short","Abriymoch, Phlegethos the fourth hell");
     set ("exits", ([   
     "east" : BAATOR+"phlegethos/city27.c",
   	     	  "north" : BAATOR+"phlegethos/city21.c"]));
reset();
	}
int reset(){
object ob1, ob2, ob3, ob4;
::reset();
 seteuid(getuid()) ;  
if (present("hamatula", this_object())  ) return 1;
ob1 = clone_object(BAATOR+"monsters/hamatula");
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/hamatula");
ob2->move(this_object());
ob3 = clone_object(BAATOR+"monsters/hamatula");
ob3->move(this_object());
ob4 = clone_object(BAATOR+"monsters/hamatula");
ob4->move(this_object());
ob1->set("protectors", ({ ob2, ob3, ob4 }));
ob1->set("protectees", ({ ob2, ob3, ob4 }));
ob2->set("protectors", ({ ob1, ob3, ob4 }));
ob2->set("protectees", ({ ob1, ob3, ob4 }));
ob3->set("protectors", ({ ob2, ob1, ob4 }));
ob3->set("protectees", ({ ob2, ob1, ob4 }));
ob4->set("protectors", ({ ob2, ob1, ob3 }));
ob4->set("protectees", ({ ob2, ob1, ob3 }));
return 1;
}

