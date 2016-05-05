#include <mudlib.h>
#include "main.h"

inherit ROOM;

object ob1, ob2;

void create()
{
    ::create();
    seteuid ( getuid() );
    set("author", "cyanide");
    set ("short", "Land of Shadow");
    set("exit_suppress", ([]) );
    set ("item_desc", ([
    ]) );
}

void init () {
    add_action ("exits","exits");
}

int exits() {
    if (adminp(TP)) return 0;
    write ("You begin to get a nasty headache.\n");
    say (NAME+" begins to look very confused.\n");
    return 1;
}

void reset() {
    ::reset();

    seteuid(getuid());
    if (!ob1) {
	ob1 = clone_object(MONST+"/shadow_warr.c");
	ob1->move(TO);
    }
    if (!ob2 && !random(3)) {
	ob2 = clone_object(MONST+"/shadow_warr.c");
	ob2 -> move(TO);
    }
}
