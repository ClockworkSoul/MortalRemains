#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
 set ("objects", ([ "pentar" : "/d/Outer/Sigil/monsters/pentar" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"You are in The Factol Pentar's Office. \n"+
"Where the doomguard meet to discuss entropy.\n") ;
     set ("short", "Pentar's Office") ;
     set ("exits", ([
	   "down" : SIGIL+"armory.c" ]));       
}
