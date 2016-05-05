#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are on Main Street in the Market Ward of Sigil.  The stench of sewage
is particularly pungent here, and almost makes you gag.
ENDLONG
  );
  set("smell", ([
  "default" :"The smell of sewage is quite pungent here, almost making you gag.\n",
  ]) ) ;
  set("short", "Main Street, Market Ward.") ;
     set ("exits", ([
	"east" : SIGIL+"mainst22.c",
	"west" : SIGIL+"mainst20.c" ]));
}
