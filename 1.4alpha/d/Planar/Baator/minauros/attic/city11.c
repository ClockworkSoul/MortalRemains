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
"Demons feed upon the homeless and unwary.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
      "south" : BAATOR+"minauros/city18.c",
       "north" : BAATOR+"minauros/city5.c",
     	  "east" : BAATOR+"minauros/city12.c"]));
reset();
	}


