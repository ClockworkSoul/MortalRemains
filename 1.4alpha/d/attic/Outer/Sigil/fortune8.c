#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     	seteuid(getuid());
     set ("objects", ([ "jemorille" : "/d/Outer/Sigil/monsters/jemorille" ]) );
	reset();
     set ("light", 1) ;
     set ("long",
"Shemeska's office.\n"+
"Please take a number.\n") ;
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"west" : SIGIL+"fortune5.c",
	"south" : SIGIL+"fortune9.c" ] ));
}
