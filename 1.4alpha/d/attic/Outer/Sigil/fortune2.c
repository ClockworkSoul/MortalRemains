#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"PLACE For The WHEEL game\n"+
"You are in a very boring room which\n"+
"Needs a long description.\n") ;
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"west" : SIGIL+"fortune1.c",
	"south" : SIGIL+"fortune3.c" ]));
}
