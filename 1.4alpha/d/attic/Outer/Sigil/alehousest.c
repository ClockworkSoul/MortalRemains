#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are on Alehouse Row in the Lower Ward of Sigil.  Remarkably enough,
there are no pubs here.  However, there is a clockmaker to the east and
some strange ruins to the west.
ENDLONG
  );
  set("short", "Alehouse Row, Lower Ward.") ;
     set ("exits", ([
	"south" : SIGIL+"mainst15.c",
	"east" : SIGIL+"handsoftime.c",
	"west" : SIGIL+"temple.c" ]));
}
