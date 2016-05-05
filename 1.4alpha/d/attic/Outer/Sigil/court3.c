#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("short", "Third Floor, Courthouse.") ;
 set("long", @ENDLONG
You are on a landing on the third floor of the Courthouse.
To the east is Hashkar's Office, and the Court of Woe is west.
ENDLONG
  ) ;
     set ("exits", ([
	"east" : SIGIL+"court4.c",
	"west" : SIGIL+"court5.c",
	"down" : SIGIL+"court2.c" ]));
}
