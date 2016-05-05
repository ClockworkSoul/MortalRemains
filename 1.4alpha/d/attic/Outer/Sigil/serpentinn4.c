#include <mudlib.h>
#include "sigil.h"
inherit ROOM ;

void create() {
     ::create();
          set ("light", 1) ;
     set ("long",
"A hallway to the private rooms of The Inn.\n"+
"Stairs lead down to the south.\n"+
	"The hallway continues to the north.\n");
  set("short", "World Serpent Inn.") ;
     set ("exits", ([
    "north" : SIGIL+"serpentinn2.c",
     "down" : SIGIL+"serpentinn5.c" ]) ) ;
}
