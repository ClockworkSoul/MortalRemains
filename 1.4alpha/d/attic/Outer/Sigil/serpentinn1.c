#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "grixitt" : "/d/Outer/Sigil/monsters/grixitt" ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You are in one of the private rooms in the World Serpent Inn.
ENDLONG
  ) ;
 set("short", "World Serpent Inn.") ;
     set ("exits", ([
	    "east" : SIGIL+"serpentinn2.c" ]));       
}
