#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "ruleofthree" : "/d/Outer/Sigil/monsters/ruleofthree" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in one of the private rooms in the World Serpent Inn.
ENDLONG
  ) ;
  set("short", "World Serpent Inn.") ;
     set ("exits", ([
	    "west" : SIGIL+"serpentinn2.c" ]));       
}
