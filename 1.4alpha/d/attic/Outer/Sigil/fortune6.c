#include <mudlib.h>
#include "sigil.h"

inherit ROOM ;

void create() {
     ::create();
     set ("light", 1) ;
     set ("long",
"Upstairs hallway.\n"+
"A lavish apartment is to your east.\n");
set ("short", "Fortune's Wheel");
     set ("exits", ([
	"south" : SIGIL+"fortune5.c",
	"east" : SIGIL+"fortune7.c" ]));
}
