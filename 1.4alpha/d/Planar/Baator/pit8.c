#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "molikroth" : "/d/Outer/Baator/monsters/molikroth"]));
     set ("light", 1) ;
     set ("long",
"This is the eighth pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Eighth pit");
     set ("exits", ([
"down" : BAATOR+"pit9.c",
"up" : BAATOR+"pit7.c" ]));
reset();
	}
