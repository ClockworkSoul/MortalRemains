#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "triel" : "/d/Outer/Baator/monsters/triel"]));
     set ("light", 1) ;
     set ("long",
"This is the seventh pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Seventh pit");
     set ("exits", ([
"portal" : "/d/Outer/Baator/malbolge/mal13.c",
	"down" : BAATOR+"pit8.c"]));
reset();
	}
