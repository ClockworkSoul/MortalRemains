#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "verden" : "/d/Outer/Sigil/monsters/verden" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"A Silky bedroom.\n"+
"The bed looks inviting.\n") ;
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"west" : SIGIL+"fortune6.c" ]));
}
