#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "xideous" : "/d/Outer/Sigil/monsters/xideous" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in a cell\n") ;
     set ("short", "Gatehouse") ;
     set ("exits", ([
         "west" : SIGIL+"gatehouse2.c" ]) ) ;
}
