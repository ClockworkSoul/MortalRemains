#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
 	set("objects" , ([ 	"troll1" : BAATOR+"monsters/troll",
 		"troll2" : BAATOR+"monsters/troll",
 			"troll3" : BAATOR+"monsters/troll"]));
 set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in a vast stinking bog.\n"+
"The fetid ground sucks at your feet as you walk.\n");
set ("short","The Stinking Bogs of Minauros");
     set ("exits", ([     
    	 "west" : BAATOR+"minauros/bog24.c"]));
reset();
	}
