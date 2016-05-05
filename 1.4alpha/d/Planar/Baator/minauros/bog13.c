#include <mudlib.h>
#include "baator.h"

inherit MINAUROS+"bogstd.c" ;

void create() {
        	::create();
     set ("exits", ([   
         "west" : BAATOR+"minauros/bog12.c",
         "east" : BAATOR+"minauros/bog14.c",  
	     "north" : BAATOR+"minauros/bog6.c",
    	 "south" : BAATOR+"minauros/bog19.c"]));
reset();
	}
