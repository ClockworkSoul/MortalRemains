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
"You stand within the walls of the palace of the lord of the layer.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
            "north" : BAATOR+"minauros/city22.c",
     	  "west" : BAATOR+"minauros/city28.c"]));
reset();
	}


