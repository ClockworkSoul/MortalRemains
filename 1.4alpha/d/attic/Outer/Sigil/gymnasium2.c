// Why was Rhys taken out?

#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
  seteuid(getuid());
     set("objects", (["rhys" : "/d/Outer/Sigil/monsters/rhys" ]) );
        reset(); 
     set ("light", 1) ;
   set("long", @ENDLONG
You stand in the office of the Factol of the Transcendant Order,
proprieter of the Great Gymnasium of Sigil.
ENDLONG
  );
  set("short", "Office of the Factol.") ;
     set ("exits", ([
"down" : SIGIL+"wproom.c",
	]));
}
