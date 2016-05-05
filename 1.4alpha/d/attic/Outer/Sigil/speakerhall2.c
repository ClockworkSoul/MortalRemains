#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "darius" : "/d/Outer/Sigil/monsters/darius" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Hall of Speakers. \n"+
"A place to gripe.\n") ;
     set ("short", "Hall of Speakers") ;
     set ("exits", ([
        "down" : SIGIL+"speakerhall1.c" ]));       
}
