#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"Great Iron Arches stand silent testimony to\n"+
"The atrocities performed here.\n");
set("short", "Temple of the Abyss");
     set ("exits", ([
	"east" : SIGIL+"doomguardst1.c"]));
}
