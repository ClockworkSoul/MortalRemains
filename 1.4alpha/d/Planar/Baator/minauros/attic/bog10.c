#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
 seteuid(getuid()) ;
 	set("objects" , ([ 	"hamatula" : BAATOR+"monsters/hamatula"]));
 set ("light", 1) ;
 set ("long",
"This is the third layer of Baator.\n"+
"You are in a vast stinking bog.\n"+
"The fetid ground sucks at your feet as you walk.\n");
set ("short","The Stinking Bogs of Minauros");
     set ("exits", ([     
     "south" : BAATOR+"minauros/bog17.c",
	 "west" : BAATOR+"minauros/bog9.c"]));
reset();
	}
