#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "ylem" : "/d/Outer/Sigil/monsters/ylem" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are at the top of a dark tower\n"+
"In the hive ward.\n") ;
     set ("short", "Top of tower") ;
     set ("exits", ([
     "down" : SIGIL+"ylemtower.c" ]) ) ;
}
