#include <mudlib.h>
#include "baator.h"

inherit PUB ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in the sinking city of Minauros itself.\n"+
"The baatezu offer drinks to the bedraggled customers here.\n"+
"Some say it is only to give thier meal more flavor.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
             "north" : BAATOR+"minauros/city35.c"]));
reset();
	}


