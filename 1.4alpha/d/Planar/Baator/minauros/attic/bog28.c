#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
 	set("objects" , ([ 	"dragturtle1" : BAATOR+"monsters/dragturtle",
 		"dragturtle2" : BAATOR+"monsters/dragturtle"]));
 set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in a vast stinking bog.\n"+
"The fetid ground sucks at your feet as you walk.\n");
set ("short","The Stinking Bogs of Minauros");
     set ("exits", ([     
    	 "west" : BAATOR+"minauros/bog27.c"]));
reset();
	}
