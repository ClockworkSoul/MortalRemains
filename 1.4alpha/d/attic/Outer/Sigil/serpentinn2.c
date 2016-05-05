#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
          set ("light", 1) ;
     set ("long",
"A hallway to the private rooms of The Inn.\n"+
"Stairs lead down to the north.\n"+
	"The hallway continues to the south.\n") ;
  set("short", "World Serpent Inn.") ;
     set ("exits", ([
     "east" : SIGIL+"serpentinn3.c",
     "west" : SIGIL+"serpentinn1.c",
		 "south" : SIGIL+"serpentinn4.c",
     "down" : SIGIL+"serpentinn.c" ]) ) ;
}
