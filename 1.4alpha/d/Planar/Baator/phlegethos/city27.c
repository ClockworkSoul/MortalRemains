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
     "east" : BAATOR+"phlegethos/city28.c",
   	     	  "west" : BAATOR+"phlegethos/city26.c"]));
reset();
	}


