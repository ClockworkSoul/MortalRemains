#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
  set("long", @ENDLONG
You are on Main Street in the Lower Ward of Sigil.
To the north lies the Foundry, and the Famous World Serpent Inn lies
to the south.
ENDLONG
  ) ;
  set("short", "Main Street, Lower Ward.") ;
     set ("exits", ([
	"north" : SIGIL+"foundry.c",
	"south" : SIGIL+"serpentinn.c",
	"east" : SIGIL+"mainst18.c",
	"west" : SIGIL+"mainst16.c" ]));
}
