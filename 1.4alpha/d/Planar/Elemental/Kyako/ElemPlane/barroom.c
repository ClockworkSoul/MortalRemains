#include <mudlib.h>
#include "plane.h"

inherit ROOM ;

void create() {
     ::create();
	seteuid(getuid());
     set ("objects", ([ "jack" : PLANE+"monsters/jack" ]) );
	reset();
     set ("light", 1) ;
     set ("long", @BarRoom
You are in a private room
in the Waterfront Bar.
BarRoom
 );
     set ("short", "Waterfront Bar") ;
     set ("exits", ([
            "down" : PLANE+"waterbar.c",
     ]) );
}
