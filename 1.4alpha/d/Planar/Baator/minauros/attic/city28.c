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
"Demons guard the palace of the lord of the city.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
	"east" : BAATOR+"minauros/city29.c",
"west" : BAATOR+"minauros/city27.c"]));
reset();
	}
int reset(){
object ob1, ob2, ob3;
::reset();
 seteuid(getuid()) ;           
if (present("cornugon", this_object())  ) return 1;
ob1 = clone_object(BAATOR+"monsters/cornugon");
ob1->move(this_object());
ob2 = clone_object(BAATOR+"monsters/cornugon");
ob2->move(this_object());
ob1->set("aggressive", 9);
ob2->set("aggressive", 9);
return 1;
}

