#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
        	seteuid(getuid());
     set ("objects", ([ "terrance" : "/d/Outer/Sigil/monsters/terrance" ]) );
	reset();
         set ("light", 1) ;
     set ("long",
"You are in the Shattered Temple.\n"+
"In the office of the Factol.\n") ;
     set ("short", "Shattered Temple") ;
     set ("exits", ([
       	"west"	: SIGIL+"temple1.c" ]) ) ;
}
