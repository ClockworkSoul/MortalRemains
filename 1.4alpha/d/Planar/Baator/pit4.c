#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "fierana" : "/d/Outer/Baator/monsters/fierana"]));
     set ("light", 1) ;
     set ("long",
"This is the fourth pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Fourth pit");
     set ("exits", ([
	"up" : BAATOR+"pit3.c",
	"down" : BAATOR+"pit5.c"]));
reset();
	}
