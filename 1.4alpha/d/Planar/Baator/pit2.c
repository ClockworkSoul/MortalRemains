#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "dispater" : "/d/Outer/Baator/monsters/dispater"]));
     set ("light", 1) ;
     set ("long",
"This is the second pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Second pit");
     set ("exits", ([
"portal" : BAATOR+"avernus/lair4.c",
		"down" : BAATOR+"pit3.c"]));
reset();
	}
