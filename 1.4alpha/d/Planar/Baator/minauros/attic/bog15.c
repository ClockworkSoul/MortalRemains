#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
  set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in a vast stinking bog.\n"+
"The fetid ground sucks at your feet as you walk.\n");
set ("short","The Stinking Bogs of Minauros");
     set ("exits", ([   
         "west" : BAATOR+"minauros/bog14.c",
         "east" : BAATOR+"minauros/bog16.c",  
	     "north" : BAATOR+"minauros/bog8.c",
    	 "south" : BAATOR+"minauros/bog21.c"]));
reset();
	}
