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
"Petitioners flee from hungry demons.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
            "south" : BAATOR+"minauros/city31.c",
     	  "west" : BAATOR+"minauros/city24.c"]));
reset();
	}


