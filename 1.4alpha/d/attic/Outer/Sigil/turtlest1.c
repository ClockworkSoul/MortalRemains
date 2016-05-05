#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You stand on Turtle Lane, another of the major roads in Sigil.
The ghastly sight of a severed, bleeding head is painted on a sign
hanging over the entrance to the building on the east.
You hear the sounds of a blacksmith to the east.
ENDLONG
  );
  set("smell", ([
   "default" : "The faint smell of sewage lingers in the air.\n",
  ]) ) ;
  set("listen", ([
   "default" : "You hear the anvil of a armor-worker to the east.\n",
  ]) ) ;
  set("short", "Turtle Lane, Market Ward.") ;
  set("item_desc", ([
   "sign" : "The sign bears a fairly realistic severed head, covered with blood and gore.\nThe sight of it brings the taste of bile to the back of your throat.\n",
  ]) ) ;
     set ("exits", ([
	"north" : SIGIL+"mainst1.c",
	"south" : SIGIL+"turtlest2.c",
	"east" : SIGIL+"severedhead.c",
	"west" : SIGIL+"loans.c" ]));
}
