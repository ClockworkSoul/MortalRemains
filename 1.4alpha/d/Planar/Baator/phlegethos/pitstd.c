#include <teleport.h>
#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    set("author", "cyanide");
    seteuid(getuid()) ;
    set("no_teleport", NO_IN_OR_OUT);
    set ("light", 1) ;
    set ("short","Pit of flame, Phlegethos the fourth hell");
    set ("long", wrap("You are on a ridge of volcanic rock "+
	"overlooking a vast pool of lava. Flames dance upon its "+
	"surface.") );
    reset();
}


void reset() {
    object ob;

    ob = present("#BLAH#", TO);
    if (!ob && !random(3)) {
	ob = clone_object(BAATOR+"monsters/pit_fiend.c");
	ob->add("id", ({ "#BLAH#" }) );
	ob->move(TO);
    }

    ::reset();
}

