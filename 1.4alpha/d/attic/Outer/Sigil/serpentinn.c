#include <mudlib.h>
#include "sigil.h"
inherit PUB ;

void create() {
     ::create();
  set("long", @ENDLONG
You stand in the (In)Famous World Serpent Inn in Sigil, reportedly
having the best ale this side of Sigil.

Commands are: menu, buy <drinkname>, powerheal <drinkname>
ENDLONG
  );
          set ("light", 1) ;
  set("short", "World Serpent Inn.") ;
     set ("exits", ([
		 "up" : SIGIL+"serpentinn2.c",
     "north" : SIGIL+"mainst17.c" ]) ) ;
}
