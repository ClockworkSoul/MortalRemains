#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are in the Guildhall Ward of Sigil, on Main Street.
It is crowded, hazy, and smells of sewage.
ENDLONG
  );
  set("short", "Main Street, Guildhall Ward.") ;
     set ("exits", ([
	"south" : SIGIL+"thiefguild.c",
	"east" : SIGIL+"mainst5.c",
	"west" : SIGIL+"mainst3.c" ]));
}
