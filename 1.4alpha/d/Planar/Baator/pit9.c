#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
        	::create();
	seteuid(getuid()) ;
set("objects", ([ "asmodeus" : "/d/Outer/Baator/monsters/asmodeus"]));
     set ("light", 1) ;
     set ("long",
"This is the ninth and last pit.,\n"+
" of Ilzarion's Interm Baator gauntlet .\n"+
"For those of you who want a challenge.\n");
set ("short","Ninth pit");
     set ("exits", ([
	"up" : BAATOR+"pit8.c"]));
reset();
	}
