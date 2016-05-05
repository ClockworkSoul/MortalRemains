#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
   	seteuid(getuid());
     set ("objects", ([ "gabberslug" : "/d/Outer/Sigil/monsters/gabberslug" ]) );
	reset();
     set ("light", 1) ;
set ("short", "The Court of Woe.");
set ("long", "The inestimable Gabberslug presiding.\n");
     set ("exits", ([
	"east" : SIGIL+"court3.c" ] ));
}
