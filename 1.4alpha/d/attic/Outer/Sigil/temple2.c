#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
        	seteuid(getuid());
     set ("objects", ([ "omott" : "/d/Outer/Sigil/monsters/omott" ]) );
	reset();
         set ("light", 1) ;
     set ("long",
"You are in the Shattered Temple.\n") ;
     set ("short", "Shattered Temple") ;
     set ("exits", ([
       	"east"	: SIGIL+"temple1.c" ]) ) ;
}
