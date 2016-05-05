#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
Main Street is one of the main streets in the town of Sigil.
It is crowded, hazy, and smells distinctly of sewage.
ENDLONG
  ) ;
  set("smell", ([
   "default" : "The scent of sewage hangs in the air here.\n",
  ]) ) ;
  set("short", "Main Street, Market Ward.") ;
     set ("exits", ([
	"east" : SIGIL+"mainst3.c",
	"west" : SIGIL+"mainst1.c"]));
}
