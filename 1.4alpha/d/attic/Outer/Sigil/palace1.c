#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "autochon" : "/d/Outer/Sigil/monsters/autochon" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are in the poorly designed Bell Tower of the Palace of the Jester.
ENDLONG
  );
  set("short", "In the Bell Tower.") ;
     set ("exits", ([
	   "down" : SIGIL+"palace.c" ]));       
}
