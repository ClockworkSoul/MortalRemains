#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
     set ("light", 1) ;
     set ("long",
"This is the first pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","First Pit");
     set ("exits", ([
	"up" : SIGIL+"mainst1.c",
	"down" : BAATOR+"pit2.c"]));
reset();
	}
