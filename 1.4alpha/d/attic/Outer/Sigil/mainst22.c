#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are on Main Street in the Market Ward of Sigil.
The center of town lies directly to the east.
ENDLONG
  );
  set("short", "Main Street, Market Ward.") ;
     set ("exits", ([
	"east" : SIGIL+"mainst1.c",
	"west" : SIGIL+"mainst21.c" ]));
}
