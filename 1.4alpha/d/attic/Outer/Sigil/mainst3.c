#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
@ENDLONG
You are on Main Street in the Market Ward.
It is crowded, hazy, and smells of sewage.
ENDLONG
  );
  set("short", "Main Street, Market Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"newtst1.c",
"south" : "/d/class/warrior/general/rooms/sigilfighterguild.c",
	"east" : SIGIL+"mainst4.c",
	"west" : SIGIL+"mainst2.c"]));
}
