#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
    	seteuid(getuid());
     set ("objects", ([ "phineas" : "/d/Outer/Sigil/monsters/phineas" , "morvun" : "/d/Outer/Sigil/monsters/morvun"  ]) );
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand before the "Gatehouse", known to commonfolk as "The Nuthouse".
ENDLONG
  );
  set("short", "Before the Gatehouse.") ;
     set ("exits", ([
     "north" : SIGIL+"gatehouse1.c",
     "south" : SIGIL+"mainst12.c" ]) ) ;
}
