#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
This is Newt Street, where all kinds of liquors can be found.
The baths lie to the east.
ENDLONG
  );
  set("short", "Newt Street, Market Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"newtst2.c",
	"south" : SIGIL+"mainst3.c",
	"east" : SIGIL+"baths.c" ]));
}
