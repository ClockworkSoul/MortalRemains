#include "../defs.h"
#include "./dezz.c"
inherit ROOM;

void create(){
seteuid(getuid());
set("light", 1);
set("short", "in the depths of a vast desert.");
set("long", @ENDLONG
The dunes that surround you seemingly go on forever.  The
sands of Linshara have well been famed for the many adventurers
that her evil sands have taken beneath her.  The sun has baked
the sand here to a thin, almost powder-like substance.  Nothing
but those native to this land could survive easily in this god
forsaken place.  You pray to your god to guide you to safety
in this horror of geography.
ENDLONG);

start_chat();
set("exits", ([ "north" : ROOMS(des2.c),
                "south" : ROOMS(out.c),
                "east" : ROOMS(des3.c),
                "west" : ROOMS(des4.c),
                "northwest" : ROOMS(des5.c),
                "northeast"  : ROOMS(des6.c),
              ]));

::create();
} 
