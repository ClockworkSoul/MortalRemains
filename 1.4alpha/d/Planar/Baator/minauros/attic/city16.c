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
"You seem to be on the main road which leads to a palace of some kind.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
      "north" : BAATOR+"minauros/city9.c",
       "south" : BAATOR+"minauros/city23.c",
       "east" : BAATOR+"minauros/city17.c",
     	  "west" : BAATOR+"minauros/city15.c"]));
reset();
	}


