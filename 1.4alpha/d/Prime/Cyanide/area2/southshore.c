#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( getuid() );
    set ("author", "cyanide");
    set ("light", 1);
    set ("short", "Lake Shore");
    set( "long", @EndText
You are in a wide cavern on the south shore of a small lake. Some
polished stone steps lead to the east, and a sheer rock face
prevents any movement around the lake to the northeast. The cavern
is dimly lit from above.
EndText
    );
    set( "exits", ([
      "east" : MAIN+"/transroom.c",
      "enter" : MAIN+"/onlake.c"
    ]) );
    set ("exit_suppress", ({"enter"}) );
    set ("exit_msg", ([
      "enter" : "$N jumps into the lake and swims out a bit.\n",
    ]) );
    set ("item_desc", ([
      "lake" : "It seems quite deep and is ice cold, but swimmable. If \n"+
      "you want to enter it, just 'enter' it...\n",
      "steps" : "They lead into some kind of dark room.\n",
      "face" : "It leads straight up.\n",
      "rock face" : "It leads straight up.\n",
    ]) );
}

void init()
{
    add_action ("lake", "go");
    add_action ("lake2", "north");
}

int lake2() {
    write ("If you want to enter the lake, just 'enter' it!\n");
    return 1;
}


int lake (string str) {
    if (str!="north") {
	return 0;
    }
    return lake2();
}
