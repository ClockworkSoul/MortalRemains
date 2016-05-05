#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
        ::create();
	seteuid(getuid());
 	     set ("objects", ([ "#PORTAL#" : "/d/Outer/Sigil/items/cy_portal" ]));
	reset();
     set ("light", 1) ;
  set("long", @ENDLONG
The Hands of Time is a large clockwork emporium; perhaps the largest
in all of Sigil.  Beautiful clocks hang from every wall, and smaller
clocks are behind the counter.  Everything is locked up right now, 
because the shop is closed currently.
ENDLONG
  );
   set("short", "The Hands of Time.") ;
  set("item_desc", ([
  "clocks" : "The clocks come in all shapes, colors, and sizes.  All of them are locked up.\n",
  ]) ) ;
     set ("exits", ([
     "west" : SIGIL+"alehousest.c" ]) ) ;
}
