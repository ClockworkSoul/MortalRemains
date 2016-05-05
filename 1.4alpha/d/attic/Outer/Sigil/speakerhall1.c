#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "cirily" : "/d/Outer/Sigil/monsters/cirily" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Hall of Speakers. \n"+
"A place to gripe.\n") ;
     set ("short", "Hall of Speakers") ;
     set ("exits", ([
        "up" : SIGIL+"speakerhall2.c",
        "south" : SIGIL+"speakerhall.c" ]));       
}
