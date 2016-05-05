#include <mudlib.h>
#include "main.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid( 0 );
    set ("author", " -{ CYANIDE }- ");
    set ("arena" ,1);
    set ("light", 1);
    set ("area_type", ([
      "blue" : 2,
      "black" : 2,
    ]) );
    set ("short", "Lake Shore");
    set( "long", @EndText
You are in a wide cavern on the north shore of a small lake. Some
polished stone steps lead to the southeast, and a sheer rock face
prevents any movement around the lake to the southwest. The cavern
is dimly lit from above.
EndText
    );
    set( "exits", ([
      "north" : MAIN+"/foggy.c",
      "enter" : MAIN+"/onlake.c"
    ]) );
    set ("exit_suppress", ({"enter"}) );
    set ("exit_msg", ([
      "enter" : "$N jumps into the lake and swims out a bit.\n",
      "southeast" : "$N climbs the stairs to the southeast\n",
    ]) );
    set ("item_desc", ([
      "lake" : "It seems quite deep and is ice cold, but swimmable. If you want\n"+
      "to enter it, just 'enter' it...\n",
    ]) );
}

void init()
{
    add_action ("lake", "go");
    add_action ("lake2", "south");
}

int lake2() {
    write ("If you want to enter the lake, just 'enter' it!\n");
    return 1;
}


int lake (string str) {
    if (str!="south") {
	return 0;
    }
    return lake2();
}
