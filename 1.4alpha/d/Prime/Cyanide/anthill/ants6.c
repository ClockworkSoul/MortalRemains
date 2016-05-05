// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
    seteuid(getuid());
    set("short", "In a tunnel.");
    set("long", wrap("You are in the entrance of a network of "+
	"tunnels beneath the gigantic anthill. There i"+
	"s light coming from above you.") );
    set("objects", ([
    ]) ) ;
    set("light", 1);
    set("exits", ([
      "up" : AREA1("a1forest27.c"),
      "west" : ROOMS(ants30),
    ]) ) ;
    ::create();
    reset();
}
/* EOF */
