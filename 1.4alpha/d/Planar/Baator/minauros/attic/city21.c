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
"There is a gaping pit of blackness here.\n");
set ("short","Sinking city of Minauros");
     set ("exits", ([   
"down" : BAATOR+"phlegethos/city15.c",
"east" : BAATOR+"minauros/city22.c"]));
reset();
	}


