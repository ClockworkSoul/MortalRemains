#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"Upstairs hallway.\n"+
"There is an office to your east.\n");
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"north" : SIGIL+"fortune6.c",
	"south" : SIGIL+"fortune4.c",
	"east" : SIGIL+"fortune8.c" ]));
}
