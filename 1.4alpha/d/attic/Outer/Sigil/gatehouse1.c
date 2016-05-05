#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "lhar" : "/d/Outer/Sigil/monsters/lhar" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in the admitting chambers\n"+
"Lhar also uses this office to ponder meaninglessness.\n") ;
  set("short", "Gatehouse.") ;
     set ("exits", ([
     "up" : SIGIL+"gatehouse2.c",
     "south" : SIGIL+"gatehouse.c" ]) ) ;
}
