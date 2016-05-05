#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
      set ("light", 1) ;
  set("short", "Prison.") ;
  set("long", @ENDLONG
You are on the upper floor of the Sigil Prison, where all the prisoners
reside in their respective cells.
ENDLONG
  ) ;
     set ("exits", ([
  "north" : SIGIL+"prison5",
  "south" : SIGIL+"prison6",
        "up" : SIGIL+"prison1.c",
        "down" : SIGIL+"prison.c",
        "east" : SIGIL+"prison4.c",
        "west" : SIGIL+"prison3.c" ]));       
}
