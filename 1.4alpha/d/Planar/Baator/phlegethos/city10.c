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
"You wind you way amongst running lava and choking gases.\n"+
"You come to a very dead end!\n");
set ("short","Abriymoch, Phlegethos the fourth hell");
     set ("exits", ([   
     "west" : BAATOR+"phlegethos/city29.c",
   	     	  "north" : BAATOR+"phlegethos/city25.c"]));
reset();
	}
int reset(){
object ob1, ob2, ob3, ob4;
::reset();
 seteuid(getuid()) ;  
if (present("cornugon", this_object())  ) return 1;
ob1 = clone_object(BAATOR+"monsters/cornugon");
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/cornugon");
ob2->move(this_object());
ob3 = clone_object(BAATOR+"monsters/cornugon");
ob3->move(this_object());
ob1->set("aggressive", 9);
ob2->set("aggressive", 9);
ob3->set("aggressive", 9);
return 1;
}

