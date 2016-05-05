#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "marian" : "/d/Outer/Sigil/monsters/marian" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Fortune's Wheel Tavern. \n"+
"A stage is set up here for the singer.\n") ;
     set ("short", "Fortune's Wheel") ;
     set ("exits", ([
	   "east" : SIGIL+"fortune2.c",
        "south" : SIGIL+"fortunepub.c",
        "up" : SIGIL+"fortune4.c" ]));       
}
