#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "levistus" : "/d/Outer/Baator/monsters/levistus"]));
     set ("light", 1) ;
     set ("long",
"This is the fifth pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","fifth pit");
     set ("exits", ([
"portal" : BAATOR+"phlegethos/city18.c",
	"down" : BAATOR+"pit6.c"]));
reset();
	}
