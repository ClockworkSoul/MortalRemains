#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "minauros" : "/d/Outer/Baator/monsters/minauros"]));
     set ("light", 1) ;
     set ("long",
"This is the third pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Third pit");
     set ("exits", ([
"up" : BAATOR+"dis/dtower1.c",
	"down" : BAATOR+"pit4.c"]));
reset();
	}
