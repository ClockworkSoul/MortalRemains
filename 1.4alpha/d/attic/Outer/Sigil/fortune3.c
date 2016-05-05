#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "zadara" : "/d/Outer/Sigil/monsters/zadara" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Bear Pit of \n"+
"The Fortune's Wheel Tavern.\n") ;
     set ("short", "The Bear Pit") ;
     set ("exits", ([
	 "north" : SIGIL+"fortune2.c" ]));       
}
