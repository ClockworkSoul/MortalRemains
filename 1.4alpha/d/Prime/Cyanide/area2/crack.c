#include "../cy.h"

inherit ROOM;

void create()
{
    ::create();
    seteuid(getuid());
    set ("author", "cyanide");
    set ("short", "A Hole in the Wall");
    set( "long", @EndText
You are in what can loosely be referred to as an opening in
the rock wall, but is in reality little more than a
claustrophobic crawl space, barely able to hold you. 
Thousands of tiny spiders crawl over you, as if protesting
your intrusion into their home - and you still cannot move
enough to brush them aside.
EndText
    );
    set( "exits", ([
      "east" : MAIN+"/volview.c",
      "west" : AREA1("a1ledge02.c"),
    ]) );
    set("pre_exit_func", "light");
    set ("item_desc", ([
      "spiders" : "You think one just crawled into your ear...\n",
    ]) );
}

void light() {
    object room;

    room = TP->query("last_location");
    if (room && (base_name(room)!="/d/Prime/Cyanide/area2/volview"))
	write("You emerge into brightness!\n");
    return;
}
