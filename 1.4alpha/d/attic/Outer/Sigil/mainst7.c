#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You stand on Main Street in Sigil, along the Guildhall Ward.
ENDLONG
  );
  set("short", "Main Street, Guildhall Ward.") ;
     set ("exits", ([
"south" : "/d/class/warrior/knight/rooms/knightguild.c",
	"east" : SIGIL+"mainst8.c",
	"west" : SIGIL+"mainst6.c" ]));
}
