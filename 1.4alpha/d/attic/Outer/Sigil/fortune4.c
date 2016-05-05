#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"Stairs lead north to the apartments.\n"+
"and down to the bar.\n");
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"north" : SIGIL+"fortune5.c",
	"down" : SIGIL+"fortune1.c" ]));
}
