#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "patch" : "/d/Outer/Sigil/monsters/patch" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are at the base of a dark tower\n"+
"In the hive ward.\n") ;
     set ("short", "Base of tower") ;
     set ("exits", ([
     "up" : SIGIL+"ylemtower1.c",
     "south" : SIGIL+"mainst13.c" ]) ) ;
}
