#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "shemeshka" : "/d/Outer/Sigil/monsters/shemeshka" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"Shemeska's quarters.\n"+
"You are in a lavish apartment in the fortune's wheel tavern.\n"+
"It is said the underworld of the planes is centered here.\n") ;
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"north" : SIGIL+"fortune8.c" ]));
}
