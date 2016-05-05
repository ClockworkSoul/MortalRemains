#include <config.h>
#include <mudlib.h>

inherit ROOM;

void create()
{
::create();
set("light", 1 );
set("short", "House of Mirrors");
set("long",@EndText
This is the entrance to the House of Mirrors. There is a shabby red
carpet covering the floor. A thousand images of yourself stare
at you as if challenging you to enter.
EndText
);
set("exits", ([
"south" : "m3.c",
"east" : "r4.c",
"west" : "r3.c",
"north" : "r1.c",
]) );
set("item_desc", ([
"carpet" : "A shabby red carpet.",
"mirror" : "A little vain, are we?",
"mirrors" : "A little vain, are we?",
]) );
}
