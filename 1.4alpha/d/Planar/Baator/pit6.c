#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set ("objects" , ([ "malagard" : "/d/Outer/Baator/monsters/malagard"]));
     set ("light", 1) ;
     set ("long",
"This is the sixth pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Sixth pit");
     set ("exits", ([
	"up" : BAATOR+"pit5.c",
	"down" : BAATOR+"pit7.c"]));
reset();
	}
