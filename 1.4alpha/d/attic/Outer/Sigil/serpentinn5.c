#include <mudlib.h>
#include "sigil.h"
inherit PUB;

void create() {
     ::create();
          set ("light", 1) ;
     set ("long",
"This is The Famous World Serpent Inn.\n"+
"The best ale this side of Toril.\n"+
"Commands are: menu , drink <drinkname>, powerheal <drinkname>\n");
  set("short", "World Serpent Inn.") ;
     set ("exits", ([
		 "up" : SIGIL+"serpentinn4.c",
     "north" : "/d/Prime/Toril/Arabel/city/mainst1.c" ]) );
}
