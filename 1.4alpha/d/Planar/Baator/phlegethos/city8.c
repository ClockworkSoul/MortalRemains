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
"South of you is the court of Flame where Fierana rules the layer.\n");
set ("short","Abriymoch, Phlegethos the fourth hell");
     set ("exits", ([   
     "south" : BAATOR+"phlegethos/city13.c",
     "north" : BAATOR+"phlegethos/city3.c",
   	     	  "west" : BAATOR+"phlegethos/city7.c"]));
reset();
	}


