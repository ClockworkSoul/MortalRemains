#include <mudlib.h>
#include "ocean.h"

inherit DEEP+"deepstd.c";

#define NAME    (string)this_player()->query("name")

void create()
{
    ::create();
    set( "exits", ([
      "west" : DEEP+"deep18.c",
    ]) );
}
void reset() {
    object ob;
    if(!present("eel")) {
	ob = clone_object(O_MON+"eleceel.c");
	ob->move(TO);
	ob = clone_object(O_MON+"eleceel.c");
	ob->move(TO);
    }
    if(!present("ursula", TO)) {
	ob = clone_object(O_MON+"ursula.c");
	ob->move(TO);
    }
}

